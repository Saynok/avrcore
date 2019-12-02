#ifndef THEFRAMEWORK_UART_H
#define THEFRAMEWORK_UART_H

#include "FIFO.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <math.h>
#include <string.h>

class xUART
{
public:
    xUART(double baudrate = 9600);
    void write(char out);
    void write(const char *string);
    int available();
    char readByte();
    void isr();
private:
    FIFO fifo;
};

#endif