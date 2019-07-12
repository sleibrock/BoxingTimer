#ifndef _PIN_H
#define _PIN_H

// Pin.h header file
#include "types.h"

class Pin
{
public:
    int     pinNum;
    PinType type;
    PinMode mode;

    Pin(int, PinType, PinMode);
    ~Pin();

    void write(int);
    int read();
};





#endif
