#ifndef _MYTYPES_H
#define _MYTYPES_H

// types.h header file
// contains all structs/enumerations we might need
// also contains #defines

// define the resolution of the clock (how much in millis is used)
// should not be changed, but if it is, modify it to a multiple
// of 1000, otherwise the clock will not add seconds appropriately
// constant assumption of 1000 milliseconds = 1 second
#define RESOLUTION 50

// compile time expression to represent ticks
#define TICKS(N) (N * RESOLUTION)


// enumerations section
enum PinType {
    Analog,
    Digital,
};

enum PinMode {
    Input,
    Output,
    InputPullup,
};

enum PinStatus {
    On,
    Off,
};

enum ClockType {
    Increment,
    Decrement,
};

enum BoxingMode {
    Break,
    Round,
};

enum BellMode {
    Warning,
    Switch,
    Inactive,
};

#endif
