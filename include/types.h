#ifndef _MYTYPES_H
#define _MYTYPES_H

// types.h header file
// contains all structs/enumerations we might need

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
};


#endif
