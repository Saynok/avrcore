#include <util/delay.h>
#include "xGPIO.h"
#include "xUART.h"
#include "pinout.h"

xGPIO output(XGPIO_PC0, XOUTPUT);
xGPIO input(XGPIO_PB3, XINPUT);
xUART uart(115200);

extern "C" int main()
{
  for (;;)
  {
    output.write(1);

    uart.write("Hello world!\n");

    _delay_ms(500);
    output.write(0);
    _delay_ms(500);
  }
}