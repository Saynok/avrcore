#ifndef THEFRAMEWORK_UART_H
#define THEFRAMEWORK_UART_H

#include <avr/io.h>
#include <string.h>


class xUART
{
public:
    xUART();
    void write(char out);
    void write(const char * string);
    int available();
    char *read();

private:
    char buffer[256];
};

#endif