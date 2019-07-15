// Pin.cpp code file

#include "Arduino.h"
#include "include/types.h"
#include "include/Pin.h"


Pin::Pin(int pn, PinType pt, PinMode pm)
{
    pinNum = pn;
    type   = pt;
    mode   = pm;
    status = PinStatus::Off;

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
    case PinMode::Input:
	return;
	break;
    case PinMode::Output:
	switch (type)
	{
	case PinType::Analog:
	    if (data > 0)
		status = PinStatus::On;
	    else
		status = PinStatus::Off;

	    analogWrite(pinNum, data);
	    break;
	case PinType::Digital:
	    digitalWrite(pinNum, data);
	    break;
	};
	break;
    case PinMode::InputPullup:
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


void Pin::on()
{
    switch (type)
    {
    case PinType::Analog:
	write(255);
	break;
    case PinType::Digital:
	write(HIGH);
	break;
    }
    return;
}

void Pin::off()
{
    switch (type)
    {
    case PinType::Analog:
	write(0);
	break;
    case PinType::Digital:
	write(LOW);
	break;
    }
    return;
}

void Pin::toggle()
{
    switch (status)
    {
    case PinStatus::On:
	status = PinStatus::Off;
	off();
	break;
    case PinStatus::Off:
	status = PinStatus::On;
	on();
	break;
    }
    return;
}

Pin::~Pin()
{
}


// end Pin.cpp
