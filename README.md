Cylon soundbox
=================
A simple sound box for cylon cosplay, included sounds are based off the original 1978 Cylon Centurions.

This could easily be adapted for any other costume you want just by replacing the included MP3s.

The DFPlayer Mini doesn't have the ability to play a sound in the background so to work around this I mixed in the eye scanning sound to each of the sound effects as well as having versions without the sound mixed in, this means the first button acts as a background sound toggle and each other button will play one of two sound effects (with or without the background sound mixed in).


This doesn't go into too much detail around creating the wearable portion of the sound glove as it's just switches and wires, I used some old 6 core alarm cable, those black micro switches that seem to come in every electronics kit and 6S lipo balance connectors as I had them spare. You should be able to make something from whatever you have spare, if you want to be a bit tidier there's an excellent tutorial for the tktalkie sound glove here (you will need to adapt things a bit): http://www.tktalkie.com/tutorial/glove

Hardware
--------
- Arduino nano or other microcontroller of choice
- DFPlayer mini
- 5 X Large or small micro switch buttons
- Hookup wire

Software
--------
This was written in VSCode using PlatformIO, if you don't have these setup and aren't interested in doing so you can just copy the contents of main.cpp to the Arduino IDE and complie it from there.

You will need to grab the DFPlayerMini_Fast library and copy it to your libraries folder as well.

Once you have flashed the Arduino just copy the contents of the MP3s folder to the root of the SD card (so folders 01-05 should be at the top level, don't copy the parent MP#s folder as well).

Wiring
------
![Picture of wiring]
(https://github.com/Xitsz/Cylon-soundbox/blob/master/images/Wiring.png "Example wiring")
![Picture of DFPlayer pinout]
(https://github.com/Xitsz/Cylon-soundbox/blob/master/images/DFPlayerPinout.png "DFPlayer Mini pinout")

