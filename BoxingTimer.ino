// BoxingTimer.ino
//
// For Arduino assistance, consult the Arduino documentation page
// https://www.arduino.cc/reference/en/

#include "include/types.h"
#include "include/Pin.h"
#include "include/Clock.h"
#include "include/Buzzer.h"
#include "include/Blinker.h"

// Compile-time constants
#define BREAKTIME    60
#define ROUNDTIME   180
#define BUZZPIN      11 // set this to your buzzer's pin
#define ROUNDPIN      7 // set these to the two pins of your LEDs
#define BREAKPIN      4
#define BLINKPIN      2
#define BUZZTIME      3
#define RESOLUTION  100 // number of milliseconds to update with

// initialize components here

// pins
Pin buzzerPin(BUZZPIN, PinType::Analog, PinMode::Output);
Pin roundPin(ROUNDPIN, PinType::Digital, PinMode::Output);
Pin breakPin(BREAKPIN, PinType::Digital, PinMode::Output);
Pin blinkPin(BLINKPIN, PinType::Digital, PinMode::Output);

// main timer clock
Clock boxClock(RESOLUTION, ClockType::Decrement);

// buzzer
Buzzer buzzer(&buzzerPin, &boxClock, BellMode::Warning);

// blinker LED
Blinker blinky(&blinkPin, &boxClock);


// Setup code (runs once)
void setup() 
{
  boxClock.set_time(180);


  return;
}


// Loop code (runs indefinitely, do not use while loops inside
void loop()
{

  boxClock.update();
  blinky.update();
  
  boxClock.wait();
  return;
}

// end BoxingTimer.ino
