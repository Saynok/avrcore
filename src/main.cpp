#include <util/delay.h>
#include "xGPIO.h"

xGPIO output(XGPIO_PC0, XOUTPUT);
xGPIO input(XGPIO_PB3, XINPUT);

extern "C" int main()
{
  output.write(1);
  _delay_ms(500);
  output.write(0);
  _delay_ms(500);

  for (;;)
  {
    output.write(input.read());
    _delay_ms(50);
  }
}