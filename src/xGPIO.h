#ifndef THEFRAMEWORK_GPIO_H
#define THEFRAMEWORK_GPIO_H

#include <avr/io.h>
#include "pinout.h"

class xGPIO
{
public:
    xGPIO(int pin, int mode );
    int read();
    void write(int state);

private:
    int _pin;
    int _port;
};
#endif