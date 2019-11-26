#ifndef THEFRAMEWORK_SYSTEM_H
#define THEFRAMEWORK_SYSTEM_H

#include "pinout.h"

class System
{
public:
    static long getFrequency()
    {
        return SYSTEM_FREQUENCY;
    }
};

#endif