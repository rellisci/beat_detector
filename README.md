# beat_detector
Simple Python to Arduino beat detector for live and imported audio

There are two python scripts in this repo, my_beat_detector.py and import_beat_track.py. my_beat_detector.py takes in live input and sends a message to arduino when an amplitude threshold has been broken. It is pretty janky. On the other hand import_beat_track.py imports a .wav file and analyses its beats using the librosa library's beat detection algorithm. These beats are given as times in seconds from the start of the file. So, using the package pyglet to play the file and time to measure the time elapsed in play, a message is sent to arduino when each beat has elapsed. It is fine, but mainly just works as a visual metronome.

Video Demonstration:
https://youtu.be/LLjjh5hFvNM
