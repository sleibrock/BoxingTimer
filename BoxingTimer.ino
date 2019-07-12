// BoxingTimer.ino
//
// For Arduino assistance, consult the Arduino documentation page
// https://www.arduino.cc/reference/en/

#include "include/types.h"
#include "include/Pin.h"
#include "include/Clock.h"

// Compile-time constants
#define BREAKTIME    60
#define ROUNDTIME   180
#define BUZZPIN      11 // set this to your buzzer's pin
#define ROUNDPIN      7 // set these to the two pins of your LEDs
#define BREAKPIN      2
#define BUZZTIME      3
#define RESOLUTION  100 // number of milliseconds to update with


Pin buzzer(BUZZPIN, PinType::Analog, PinMode::Output);
Pin roundLED(ROUNDPIN, PinType::Digital, PinMode::Output);
Pin breakLED(BREAKPIN, PinType::Digital, PinMode::Output);

Clock boxClock(100, ClockType::Decrement);



// Setup code (runs once)
void setup()
{

  roundLED.on();
  breakLED.on();

  return;
}


// Loop code (runs indefinitely, do not use while loops inside
void loop()
{

  roundLED.toggle();


  boxClock.wait();
  return;
}

// end BoxingTimer.ino
