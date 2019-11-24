#include "xGPIO.h"

xGPIO::xGPIO(int num, int mode)
{
    if (num >= XGPIO_PB0 && num <= XGPIO_PB7)
    {
        _ddr = &DDRB;
        _port =  &PORTB;
        _pin = &PINB;
        _num = num - XGPIO_PB0;
    }
    else if (num >= XGPIO_PC0 && num <= XGPIO_PC6)
    {
        _ddr = &DDRC;
        _port =  &PORTC;
        _pin = &PINC;
        _num = num - XGPIO_PC0;
    }
    else if (num >= XGPIO_PD0 && num <= XGPIO_PD7)
    {
        _ddr = &DDRD;
        _port =  &PORTD;
        _pin = &PIND;
        _num = num - XGPIO_PD0;
    }

    if (mode == XOUTPUT)
        (*_ddr) |= (1 << _num);
    else
        (*_ddr) &= ~(0 << _num);
}

int xGPIO::read()
{
    return !bit_is_clear((*_pin), _num);
}

void xGPIO::write(int state)
{
    (*_port) = state << _num;
}
