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
    uint8_t _num;
    volatile uint8_t * _port;
    volatile uint8_t * _ddr;
    volatile uint8_t * _pin;
};
#endif