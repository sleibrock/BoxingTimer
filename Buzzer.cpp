#include "include/types.h"
#include "include/Buzzer.h"



Buzzer::Buzzer(Pin *p, Clock *c)
{
    pin = p;
    clock = c;
}


void Buzzer::update()
{
}


Buzzer::~Buzzer()
{
}


// end Buzzer.cpp
