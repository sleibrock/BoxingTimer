#include "include/types.h"
#include "include/Buzzer.h"



Buzzer::Buzzer(Pin *p, Clock *c, BellMode bm)
{
    pin = p;
    clock = c;
    mode = bm;
}

Buzzer::~Buzzer()
{
}


// end Buzzer.cpp
