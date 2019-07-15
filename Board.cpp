// Board.cpp

#include "include/Board.h"




Board::Board(Pin *r, Pin* b, Clock* c, Blinker* bl, Buzzer* bz)
{
    roundLED = r;
    breakLED = b;
    clock = c;
    blinky = bl;
    buzz = bz;

    bm = BoxingMode::Break;
}

void Board::init_state()
{
    (*clock).set_time(60);
    bm = BoxingMode::Break;
    (*breakLED).on();
    return;
}


void Board::update()
{
    // first update the clock globally
    (*clock).update();

    // update any time-based components
    (*blinky).update();

    // toggle between modes/LEDs based on clock
    switch ((*clock).seconds)
    {
    case 10:
	// ring the 10 second bell
	break;
    case 0:
	// switch the rounds, ring the bell
	switch (bm)
	{
	case BoxingMode::Break:
	    bm = BoxingMode::Round;
	    (*breakLED).off();
	    (*roundLED).on();
	    (*clock).set_time(180);
	    break;
	case BoxingMode::Round:
	    bm = BoxingMode::Break;
	    (*breakLED).on();
	    (*roundLED).off();
	    (*clock).set_time(60);
	    break;
	}
	break;
    
    }


    (*clock).wait();

    return;
}



Board::~Board()
{
}