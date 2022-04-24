###########
# Imports #
###########
from operator import index
import numpy as np
import pyaudio as pa
import struct
import matplotlib.pyplot as plt
import serial
import time

###########################
# Init Audio In Variables #
###########################

CHUNK = 512 * 2 # no of samples per second
FORMAT = pa.paInt16
CHANNELS = 1 # single mic with one channel
RATE = 22050 # sr in Hz

p = pa.PyAudio()

######################
# Start Serial Comms #
######################
arduino = serial.Serial(port='COM4', baudrate=9600, timeout=0.1)

###########################################
# Set up Writing and Reading from Arduino #
###########################################
def write_read(x):
    arduino.write(bytes(x, 'utf-8'))
    time.sleep(0.2)
    # data = arduino.readline()
    # return data

#####################
# Init Audio Stream #
#####################
stream = p.open(
    format = FORMAT,
    channels = CHANNELS,
    rate = RATE,
    input = True,
    output = True,
    frames_per_buffer = CHUNK
)


# always run
while 1:
    # read data from mic in
    data = stream.read(CHUNK)
    # print(data)

    # chunk is size of data, h is type
    dataInt = struct.unpack(str(CHUNK)+'h', data) 

    print(time.localtime())
    #always printing below
    previousPrint = "below"
    # for each sample point
    for i in range(CHUNK): 
        # simple amplitude threshold (change to make more sensitive)
        if dataInt[i]>6000:
            print('above') # above threshold
            # this if statement stops repeats in Serial data being sent
            # usually a large number of i's in CHUNK will be above the threshold
            # (a beat is generally not a single impulse)
            # so this checks if the previousPrint val is below and if so, this means
            # this is the start of the transient
            if previousPrint == "below":
                write_read('1')
            previousPrint = "above"

# NOTE:
# lots of trouble with audio in, any complex calculations or 
# simultaneous processes caused my laptop to crash, so this basic
# amplitude threshold was the most reasonable implementation

  