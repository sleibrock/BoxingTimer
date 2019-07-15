// Buzzer.h header file

#ifndef _BUZZER_H
#define _BUZZER_H

#include "types.h"
#include "Pin.h"
#include "Clock.h"


class Buzzer
{
public:
    Pin *pin;
    Clock *clock;
    
    Buzzer(Pin*, Clock*);
    ~Buzzer();


    void update();
};



#endif

// end Buzzer.h
