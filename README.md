# Curtain-Control

This simple arduino program works to run a 12V motor/pulley system to open and close curtains.

## Setup and Usage

The basic flow of this system works as follows:
1) The 315mhz receiver gets the signal from a remote
2) The arduino checks its current state and acts accordingly
3) If the curtain gets to one side or the other, a proximity switch is hit causing the motors to stop

(A more detailed state diagram is given in the "Curtain System" Power Point)
