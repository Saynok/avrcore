#include "xUART.h"

xUART::xUART(double baudrate)
{

    UCSR0A = 0x00;
    UCSR0B = 1 << RXEN0 | 1 << TXEN0 | 1 << RXCIE0 | 1 << TXCIE0;
    UCSR0C = 1 << UMSEL01 | 1 << UCSZ00 | 1 << UCSZ01;

    // setting baudrate
    double divider;
    if (baudrate > 1000000)
    {
        divider = (16000000 / 8.0f / baudrate) - 1;
        UCSR0A |= 1 << U2X0;
    }
    else
    {
        divider = (16000000 / 16.0f / baudrate) - 1;
        UCSR0A &= ~(0 << U2X0);
    }

    UBRR0H = ((int)round(divider)) >> 8;
    UBRR0L = ((int)round(divider));

    sei();
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
    for (int i = 0; i < length; i++)
    {
        while (!(UCSR0A & (1 << UDRE0)))
        {
        }
        UDR0 = data[i];
    }
}

int xUART::available() // 55 & 11
{
    return fifo.getLength();
}

char xUART::readByte()
{
    return fifo.get();
}

void xUART::isr()
{
    fifo.put(UDR0);
}
