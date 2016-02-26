// This code provides "signs of life": routes internal high speed clock to MCO pin 29 and toggles GPIO PA9 on pin 30
// PA9 can drive a small LED via a 390 ohm resistor
// Requires startup assembly file startup.s, register header file STM32F100.h, link script STM32F100.ld and a Makefile
// Liam Goudge Feb 2015


#include "STM32F100.h"
int main(void)

{

  // First set up power to the GPIO unit and allocate pins 29 & 30 to MCO clock and toggled port respectively
  RCC_APB2ENR= 0x4; // Start clock to GPIO port A

  GPIOA_CRH = 0x19; // Set PA8 to be alternate function push pull 10 MHz bandwidth.
                    // Set PA9 to be GPIO output 10MHz bandwidth

  //Set the Clock config register to output High Speed Internal 8MHz clock at MCO pin 29
  RCC_CFGR=0x5000000;

  // Now pulse pin PA9 in a loop. i=80000 is about 1sec
  int i=0;
  int j=99;

  while(1) //
  {
	  GPIOA_BSRR=0x200; // Set PA9
	  for (i=0;i<0x80000;i++);
	  GPIOA_BSRR=0x2000000; // Clear PA9
	  for (i=0;i<0x80000;i++);

      }

}
