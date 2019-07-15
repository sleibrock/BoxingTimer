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
    // Blinker state is based purely on milliseconds
    // Check <Clock.h>'s RESOLUTION #define to see
    // how that's defined
    // Switch statements are inherently fixed and need
    // compile-time expressions
    switch ((*clock).milliseconds)
    {
    case 0:
	(*pin).on();
	break;
    case 50:
	(*pin).off();
	break;
    }
    
    return;
}

Blinker::~Blinker()
{
}


// end Blinker.cpp
