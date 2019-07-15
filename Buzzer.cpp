#include "include/types.h"
#include "include/Buzzer.h"

#define SWITCHTONE   80 
#define WARNTONE1   150
#define WARNTONE2   170
#define WARNTONE3   190

Buzzer::Buzzer(Pin *p, Clock *c)
{
    pin   = p;
    clock = c;
    ticks = 0;
    mode  = BellMode::Inactive;
}

void Buzzer::set_mode(BellMode nbm)
{
    mode = nbm;
    ticks = 0;
}


void Buzzer::update()
{
    switch (mode)
    {
    case BellMode::Warning:
	switch (ticks)
	{
	case TICKS(0):
	    (*pin).write(WARNTONE1);
	    break;
	case TICKS(1):
	    (*pin).off();
	    break;
	case TICKS(10):
	    (*pin).write(WARNTONE2);
	    break;
	case TICKS(15):
	    (*pin).off();
	    break;
	case TICKS(20):
	    (*pin).write(WARNTONE3);
	    break;
	case TICKS(25):
	    (*pin).off();
	    mode = BellMode::Inactive;
	    break;
	}
	ticks += (*clock).resolution;
	break;

    case BellMode::Switch:
	switch (ticks)
	{
	case TICKS(0):
	    (*pin).write(SWITCHTONE);
	    break;
	case TICKS(60):
	    (*pin).off();
	    mode = BellMode::Inactive;
	    break;
	}
	ticks += (*clock).resolution;
	break;

    case BellMode::Inactive:
	break;
    }
    return;
}


Buzzer::~Buzzer()
{
}


// end Buzzer.cpp
