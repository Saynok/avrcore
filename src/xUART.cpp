#include "xUART.h"

xUART::xUART(double baudrate, long parity, long stopBit)
{
    UCSR0A = 0x00;
    UCSR0B = 0x08;
    UCSR0C = 0x86;


    // setting baudrate
    double divider;
    if (baudrate > 1000000)
    {
        divider = (System::getFrequency() / 8.0f / baudrate) - 1;
        UCSR0A |= 1 << U2X0;
    }
    else
    {
        divider = (System::getFrequency() / 16.0f / baudrate) - 1;
        UCSR0A &= ~(0 << U2X0);
    }

    UBRR0H = ((int)round(divider)) >> 8;
    UBRR0L = ((int)round(divider));
}

void xUART::write(char out)
{
    while (!(UCSR0A & (1 << UDRE0)))
        ;
    UDR0 = out;
}

void xUART::write(const char *data)
{
    int length = strlen(data);
    for (size_t i = 0; i < length; i++)
    {
        while (!(UCSR0A & (1 << UDRE0)))
        {
        }
        UDR0 = data[i];
    }
}

int xUART::available()
{
    return 0;
}

char *xUART::read()
{
    return 0;
}