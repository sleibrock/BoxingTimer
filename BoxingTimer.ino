// BoxingTimer.ino
//
// For Arduino assistance, consult the Arduino documentation page
// https://www.arduino.cc/reference/en/

#include "include/types.h"
#include "include/Pin.h"


#define BREAKTIME   60
#define ROUNDTIME  180
#define BUZZPIN     11 // set this to your buzzer's pin
#define ROUNDPIN     7 // set these to the two pins of your LEDs
#define BREAKPIN     2
#define BUZZTIME     3


// Declare variables (leave uninitialized)
BoxingMode current_mode;
byte current_time; // maximum possible value is 255

int buzzer_pin;    // find a pin to output a PWM to the Piezo speaker
int round_led_pin; // allocate a pin for the ROUND status LED
int break_led_pin; // allocate a pin for the BREAK status LED
int tmp_pin;       // tmp for swap purposes
//

Pin buzzer(BUZZPIN, Analog, Output);
Pin roundLED(ROUNDPIN, Digital, Output);
Pin breakLED(BREAKPIN, Digital, Output);


// swap two values A and B
// an external tmp variable is also required
void swap(int *a, int *b, int *tmp)
{
  *tmp = *a;
  *a = *b;
  *b = *tmp;

  return;
}

void dummy_func(int value)
{
  return;
}

// Play the Piezo buzzer for a short duration
void play_buzzer(byte *timer, BellMode mode)
{
  // TODO: buzzer stuff
  if (mode == Switch)
  {
    switch (*timer)
    {
      case 180:
        analogWrite(BUZZPIN, 128);
        break;
      case 177:
        analogWrite(BUZZPIN, 0);
        break;
    }
  } else {
    switch (*timer)
    {
      case 10:
        analogWrite(BUZZPIN, 145);
        break;
      case 9:
        analogWrite(BUZZPIN, 0);
    }
    
  }
}


// use the swap function to turn off one pin and another on
void alternate_leds(int *a, int *b, int *tmp)
{
  // turn the A pin off
  digitalWrite(*a, LOW);

  // turn the B pin on
  digitalWrite(*b, HIGH);

  // swap the two for the next alternation
  swap(a, b, tmp);
}


// Set our timer based on our current mode,
// and invert the mode to the next phase
void set_time_invert_mode(byte* timer, BoxingMode *bm)
{
  switch (*bm)
  {
    case Break:
      *bm    = Round;
      *timer = ROUNDTIME;
      break;
    case Round:
      *bm = Break;
      *timer = BREAKTIME;
      break;
  }

  return;
}


// Setup code (runs once)
void setup() {
  // on start, we start in a Break
  // set current_time to BREAKTIME
  current_mode = Break; // pointless reassign
  current_time = BREAKTIME;

  // get pins ready for WRITE outputs
  pinMode(ROUNDPIN, OUTPUT);
  pinMode(BREAKPIN, OUTPUT);
  pinMode(BUZZPIN, OUTPUT);

  //analogWrite(BUZZPIN, 128);

  dummy_func(HIGH);

  return;
}


// Loop code (runs indefinitely)
void loop() {
  // put your main code here, to run repeatedly:

  // run a check to see if our timer is for some reason, at zero
  // this could be the result of poor initialization / code errors
  // if your timer starts hopping between modes, this will probably
  // help notify you something is off
  if (current_time == 0)
  {
    current_time = 1;
    return;
  }

  // subtract from our timer
  current_time -= 1;

  // check if we need to turn the buzzer pin on
  // there will be a normal check and a x<=10 check
  play_buzzer(&current_time, Switch);
  if (current_time <= 10)
    play_buzzer(&current_time, Warning);

  // check if it equals zero
  if (current_time == 0)
  {
    set_time_invert_mode(&current_time, &current_mode);
  }

  // delay 1000 milliseconds (one second)
  delay(1000);

  return;
}

// end boxing timer program
