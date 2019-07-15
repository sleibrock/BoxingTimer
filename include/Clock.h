// Clock.h header file

#ifndef _CLOCK_H
#define _CLOCK_H

#include "types.h"

// define the resolution of the clock (how much in millis is used)
// should not be changed, but if it is, modify it to a multiple
// of 1000, otherwise the clock will not add seconds appropriately
// constant assumption of 1000 milliseconds = 1 second
#define RESOLUTION 50



class Clock
{
public:
    int resolution;
    int milliseconds;
    int seconds;
    ClockType type;

    Clock(ClockType);
    ~Clock();

    void set_time(int);
    void update();

    void wait();
};



#endif

// end Clock.h
