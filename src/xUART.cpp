#include "xUART.h"

xUART::xUART()
{
    UCSR0A = 0x00;
    UCSR0B = 0x08;
    UCSR0C = 0x86;
    UBRR0H = 0x00;
    UBRR0L = 0x67;
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
}

char *xUART::read()
{
}