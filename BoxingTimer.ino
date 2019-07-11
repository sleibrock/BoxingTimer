// BoxingTimer.ino
//
// For Arduino assistance, consult the Arduino documentation page
// https://www.arduino.cc/reference/en/

#define BREAKTIME   60;
#define ROUNDTIME  180;
#define BUZZPIN      0; // set this to your buzzer's pin
#define ROUNDPIN     0; // set these to the two pins of your LEDs
#define BREAKPIN     0;
#define BUZZTIME     3;


// Define the modes of our clock
enum BoxingMode {
  Break,
  Round,
};


// Declare variables (leave uninitialized)
BoxingMode current_mode;
byte current_time; // maximum possible value is 255

//int buzzer_pin;    // find a pin to output a PWM to the Piezo speaker
//int round_led_pin; // allocate a pin for the ROUND status LED
//int break_led_pin; // allocate a pin for the BREAK status LED

//

// Play the Piezo buzzer for a short duration
void play_buzzer()
{
  // TODO: buzzer stuff
}


// Invert our Boxing mode function
// Used when we want to switch modes on the timer
void invert_mode(BoxingMode *bm)
{
  switch (*bm)
  {
    case Break:
      *bm = Round;
      break;
    case Round:
      *bm = Break;
      break;
  }
  return;
}

void set_time(byte *timer, BoxingMode *bm)
{
  switch (*bm)
  {
    case Break:
      *timer = BREAKTIME;
      break;
    case Round:
      *timer = ROUNDTIME;
      break;
  }
}


// Setup code (runs once)
void setup() {
  // on start, we start in a Break
  // set current_time to BREAKTIME
  current_mode = Break; // pointless reassign
  current_time = BREAKTIME;

  // get pins ready for WRITE outputs
  //pinMode(0, OUTPUT);
  //pinMode(0, OUTPUT);

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

  // check if it equals zero
  if (current_time == 0)
  {
    invert_mode(&current_mode);
    set_time(&current_time, &current_mode);
    play_buzzer();

  }

  // delay 1000 milliseconds (one second)
  delay(1000);

  return;
}

// end boxing timer program
