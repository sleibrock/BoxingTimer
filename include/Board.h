// Board.h header

#ifndef _BOARD_H
#define _BOARD_H


#include "Pin.h"
#include "Clock.h"
#include "Blinker.h"
#include "Buzzer.h"

class Board
{
public:

    Pin* roundLED;
    Pin* breakLED;
    Clock* clock;
    Blinker* blinky;
    Buzzer* buzz;

    BoxingMode bm;


    Board(Pin*, Pin*, Clock*, Blinker*, Buzzer*);
    ~Board();

    void init_state();

    void update();
    void wait();

};




#endif
