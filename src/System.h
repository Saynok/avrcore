#ifndef THEFRAMEWORK_SYSTEM_H
#define THEFRAMEWORK_SYSTEM_H

#include "avr/interrupt.h"
#include "xUART.h"



class System
{
public:
    static xUART *getUART()
    {
        return _uart;
    }

    static void setUART( xUART *uart)
    {
        _uart = uart;
    }

private:
     static xUART *_uart;
};

// Vectors


#endif