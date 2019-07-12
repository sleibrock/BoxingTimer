// Blinker.h

#ifndef _BLINKER_H
#define _BLINKER_H

#include "Pin.h"
#include "Clock.h"


class Blinker
{
public:
    Pin *pin;
    Clock *clock;

    Blinker(Pin*, Clock*);
    ~Blinker();

    void update();
};


#endif

// end Blinker.h
