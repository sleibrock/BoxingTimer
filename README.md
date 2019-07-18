Boxing Timer Arduino
====================

A simple clock/timer board and program for those who need a timer but
would much prefer it if it were on an Arduino board.

Workout is a simple 3-minute round / 1 minute break routine. Can be
adjusted to have longer rounds / shorter breaks etc by editing the
source file's `#define` constants at the top.

## Design

Here is the design this project currently uses.

![Boxing Timer schematic](https://raw.githubusercontent.com/sleibrock/BoxingTimer/master/docs/design.png)

The parts would be as follows:

* Arduino UNO
* Piezo buzzer/speaker
* 3 different single-color LEDs
* resistors
* USB or 5v/2.5a power supply

All three LEDs should be set to any pin, but the Piezo must be connected to a PWM pin. You can change your pin settings in the main `BoxingTimer.ino` file. 
