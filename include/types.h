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

enum BoxingMode {
    Break,
    Round,
};

enum BellMode {
    Warning,
    Switch,
};


#endif
