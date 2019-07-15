// Buzzer.h header file

#ifndef _BUZZER_H
#define _BUZZER_H

#include "types.h"
#include "Pin.h"
#include "Clock.h"


class Buzzer
{
public:
    int ticks;
    Pin *pin;
    Clock *clock;
    BellMode mode;
    
    Buzzer(Pin*, Clock*);
    ~Buzzer();


    void set_mode(BellMode);
    void update();
};



#endif

// end Buzzer.h
