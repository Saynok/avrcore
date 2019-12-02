#include "Constants.h"
#include "xGPIO.h"
#include "xUART.h"
#include "avr/delay.h"

xGPIO output(XGPIO_PC0, XOUTPUT);
xGPIO led(XGPIO_PB5, XOUTPUT);
xGPIO input(XGPIO_PB3, XINPUT);
xUART uart1(2000000);

ISR(USART_RX_vect)
{
    uart1.isr();
}

extern "C" int main()
{
  for (;;)
  {
    //output.write(1);
    while (uart1.available() > 0)
      uart1.write(uart1.readByte());
    _delay_ms(20);
  }
}
