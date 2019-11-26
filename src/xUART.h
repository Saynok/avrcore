#ifndef THEFRAMEWORK_UART_H
#define THEFRAMEWORK_UART_H

#include <avr/io.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include "System.h"


class xUART
{
public:
    xUART(double baudrate = 9600, long parity = 0, long stopBit = 0);
    void write(char out);
    void write(const char * string);
    int available();
    char *read();


private:
    char buffer[256];
};

#endif