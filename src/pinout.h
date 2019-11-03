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
    XGPIO_0 = PB0,
    XGPIO_1 = PB1,
    XGPIO_2 = PB2,
    XGPIO_3 = PB3,
    XGPIO_4 = PB4,
    XGPIO_5 = PB5, // usually using for LED
    XGPIO_6 = PB6,
    XGPIO_7 = PB7,

    XGPIO_8 = PC0,
    XGPIO_9 = PC1,
    XGPIO_10 = PC2,
    XGPIO_11 = PC3,
    XGPIO_12 = PC4,
    XGPIO_13 = PC5,
    XGPIO_14 = PC6,

    XGPIO_15 = PD0,
    XGPIO_16 = PD1,
    XGPIO_17 = PD2,
    XGPIO_18 = PD3,
    XGPIO_19 = PD4,
    XGPIO_20 = PD5,
    XGPIO_22 = PD7,

};

#endif