// Pin.cpp code file

#include "Arduino.h"
#include "include/types.h"
#include "include/Pin.h"


Pin::Pin(int pn, PinType pt, PinMode pm)
{
    pinNum = pn;
    type   = pt;
    mode   = pm;

    // set the pin mode
    switch (type)
    {
    case Input:
	pinMode(pinNum, INPUT);
	break;
    case Output:
	pinMode(pinNum, OUTPUT);
	break;
    case InputPullup:
	pinMode(pinNum, INPUT_PULLUP);
	break;
    }
}


void Pin::write(int data)
{
    // TODO: support INPUT_PULLUP
    switch (mode)
    {
    case Input:
	return;
	break;
    case Output:
	switch (type)
	{
	case Analog:
	    analogWrite(pinNum, data);
	    break;
	case Digital:
	    digitalWrite(pinNum, data);
	    break;
	};
	break;
    }
    return;
};

int Pin::read()
{
    // TODO: support INPUT_PULLUP
    switch (mode)
    {
    case Output:
	return 0;
	break;
    case Input:
	switch (type)
	{
	case Analog:
	    return analogRead(pinNum);
	    break;
	case Digital:
	    return digitalRead(pinNum);
	    break;
	}
    }
    return 0;
}

Pin::~Pin()
{
}


// end Pin.cpp
