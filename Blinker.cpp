// Blinker.cpp


#include "include/types.h"
#include "include/Pin.h"
#include "include/Clock.h"
#include "include/Blinker.h"

// currently duration is hard-coded as a macro
#define DURATION 100


Blinker::Blinker(Pin *p, Clock *c)
{
    pin = p;
    clock = c;
}


void Blinker::update()
{
    switch ((*clock).milliseconds)
    {
    case 0:
	(*pin).on();
	break;
    case 100:
	(*pin).off();
	break;
    }
    
    return;
}

Blinker::~Blinker()
{
}


// end Blinker.cpp
