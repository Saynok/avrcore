#include <avr/delay.h>
#include "xGPIO.h"

xGPIO output(XGPIO_PB5, XOUTPUT);
xGPIO input(XGPIO_PB3, XINPUT);

extern "C" int main()
{
  for (;;)
  {
    output.write(input.read());
    _delay_ms(50);
  }
}