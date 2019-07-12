// Clock.h header file

#ifndef _CLOCK_H
#define _CLOCK_H

#include "types.h"


class Clock
{
public:
    int resolution;
    int milliseconds;
    int seconds;
    ClockType type;

    Clock(int, ClockType);
    ~Clock();

    void set_time(int);
    void update();

    void wait();
};



#endif

// end Clock.h
