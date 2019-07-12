#include "Arduino.h"
#include "include/Clock.h"


Clock::Clock(int reso, ClockType ct)
{
    resolution = reso;
    type = ct;
    milliseconds = 0;
    seconds = 0;
}

// Set the seconds time on the clock to a given time
// This will completely refresh the milliseconds count
void Clock::set_time(int s)
{
    seconds = s;
    milliseconds = 0;

    return;
}

void Clock::update()
{
    milliseconds += resolution;

    // check if milliseconds hit 1000, meaning 1 second passed
    if (milliseconds >= 1000)
    {
	switch (type)
	{
	case ClockType::Increment:
	    seconds += 1;
	    break;
	case ClockType::Decrement:
	    seconds -= 1;
	    break;
	}
    }
}

void Clock::wait()
{
    delay(resolution);
}


Clock::~Clock()
{
}


// end Clock.cpp
