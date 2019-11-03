#include "xGPIO.h"

xGPIO::xGPIO(int pin, int mode)
{
    _pin = pin;
    if (mode == XOUTPUT)
    {
        DDRB |= 1 << pin;
        DDRD &= ~PD7;
    }
    else
    {
        DDRB &= ~(1 << pin);
        PORTB |= (1 << pin);
    }
}

int xGPIO::read()
{
    return !bit_is_clear(PINB, 3);
}

void xGPIO::write(int state)
{
    PORTB = state << _pin;
}
