// BoxingTimer.ino
//
// For Arduino assistance, consult the Arduino documentation page
// https://www.arduino.cc/reference/en/

#include "include/types.h"
#include "include/Pin.h"
#include "include/Clock.h"
#include "include/Buzzer.h"
#include "include/Blinker.h"
#include "include/Board.h"

// Compile-time constants
#define BREAKTIME    60
#define ROUNDTIME   180
#define BUZZPIN      11 // set this to your buzzer's pin
#define ROUNDPIN      7 // set these to the two pins of your LEDs
#define BREAKPIN      4
#define BLINKPIN      2 // set this to a pin to blink every 1 second

// initialize components here

// pins
Pin buzzerPin(BUZZPIN, PinType::Analog, PinMode::Output);
Pin roundPin(ROUNDPIN, PinType::Digital, PinMode::Output);
Pin breakPin(BREAKPIN, PinType::Digital, PinMode::Output);
Pin blinkPin(BLINKPIN, PinType::Digital, PinMode::Output);

// main timer clock
Clock boxClock(ClockType::Decrement);

// buzzer
Buzzer buzzer(&buzzerPin, &boxClock);

// blinker LED
Blinker blinky(&blinkPin, &boxClock);

// Create a board to link components together
Board boardState(&roundPin, &breakPin, &boxClock, &blinky, &buzzer);


// Setup code (runs once)
void setup() 
{
  boardState.init_state();
  return;
}


// Loop code (runs indefinitely, do not use while loops inside
void loop()
{

  boardState.update();
  return;
}

// end BoxingTimer.ino
