#ifndef THEFRAMEWORK_PINOUT_H
#define THEFRAMEWORK_PINOUT_H
#include <avr/io.h>

//==========================================================================
// GPIO
//==========================================================================

enum gpio_modes
{
    XINPUT = 0,
    XOUTPUT = 1
};

enum gpio_names
{
    XGPIO_PB0 = 0,
    XGPIO_PB1,
    XGPIO_PB2,
    XGPIO_PB3,
    XGPIO_PB4,
    XGPIO_PB5, // usually using for LED
    XGPIO_PB6,
    XGPIO_PB7,

    XGPIO_PC0,
    XGPIO_PC1,
    XGPIO_PC2,
    XGPIO_PC3,
    XGPIO_PC4,
    XGPIO_PC5,
    XGPIO_PC6,

    XGPIO_PD0,
    XGPIO_PD1,
    XGPIO_PD2,
    XGPIO_PD3,
    XGPIO_PD4,
    XGPIO_PD5,
    XGPIO_PD7,
};

enum arduino_names
{
    D11 = XGPIO_PB0,
    D13 = XGPIO_PB5 // usually using for LED
};

#endif