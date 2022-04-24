###########
# imports #
###########
# from anyio import current_time
import numpy, scipy, matplotlib.pyplot as plt, IPython.display as ipd
import librosa, librosa.display
import pyglet # for playback
from pyglet.gl import *
import time
import sys
import serial

##############
# Load Audio #
##############
# .mp3 will throw a warning but the files are small enough to upload to github
x, sr = librosa.load('drumloop_EQd.mp3')
# x, sr = librosa.load('a1.wav')
ipd.Audio(x, rate=sr)

# get duration of file
duration = librosa.core.get_duration(y=x, sr=sr)

##########################################
# Get Beat Times and Tempo Using Librosa #
##########################################
tempo, beat_times = librosa.beat.beat_track(x, sr=sr, start_bpm=60, units='time')

# print(tempo)
# print(beat_times)

# get no. of beats to use later to exit after end of song
no_of_beats = (len(beat_times))
print("no of beats:")
print(no_of_beats)

#######################################################
# Plot Beats on Waveplot using Matlabplot and librosa #
#######################################################
plt.figure(figsize=(8, 2))
librosa.display.waveshow(x, sr=sr)
plt.vlines(beat_times, -1, 1, color='r')
plt.ylim(-1, 1)
plt.show()

##############################
# Start Serial Communication #
##############################
arduino = serial.Serial(port='COM4', baudrate=9600, timeout=.1)

###########################################
# Set up Writing and Reading from Arduino #
###########################################
def write_read(x):
    arduino.write(bytes(x, 'utf-8'))
    time.sleep(0.05)
    data = arduino.readline()
    return data

########################
# Start Audio Playback #
########################
pyglet.options['audio'] = ('openal','directsound','silent')
music = pyglet.resource.media('drumloop_EQd.mp3')
# music = pyglet.resource.media('a1.wav')
music.play()
pyglet.app.run

########################
# Init timer variables #
########################
starttime = time.time()
elapsedtime = starttime - starttime

###################################################################################
# Check if the time of each beat has been reached, then send a message to arduino #
###################################################################################

# keep going until audio file has ended
while elapsedtime < duration:
    # calculate current elapsed time
    elapsedtime = time.time() - starttime
    for i in range(1,no_of_beats):
        # stay in while loop until elapsed time is greater than the beat time
        while elapsedtime < beat_times[i]:
             elapsedtime = time.time() - starttime
        write_read('1')             
        print("Beat no: "+ str(i))
        print("Time: " + str(elapsedtime))
        if(elapsedtime > beat_times[no_of_beats-1]):
            time.sleep(2) # gives time for last beat and outro of song to be played
            sys.exit()
#######        
# END #
#######
print("finito")

            
