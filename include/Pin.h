// Pin.h header file

#ifndef _PIN_H
#define _PIN_H

#include "types.h"

class Pin
{
public:
    int       pinNum;
    PinType     type;
    PinMode     mode;
    PinStatus status;

    Pin(int, PinType, PinMode);
    ~Pin();

    void write(int);
    int read();

    void on();
    void off();
    void toggle();
};

#endif

// end Pin.h
