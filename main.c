// This code provides "signs of life": routes internal high speed clock to MCO pin 29, toggles GPIO PA9 on pin 30 and PA10 on pin 31
// PA9 and PA10  drive a small LED via 680 ohm resistors
// Requires startup assembly file StartUp_simple.s, register header file STM32F100.h, link script STM32F100C8_simple.ld and a Makefile
// Simplest possible boot environment
// Liam Goudge Feb 2015
// Updated Aug 2016


#include "STM32F100.h"
int main(void)

{

  // First set up power to the GPIO unit and allocate pins 29 & 30 to MCO clock and toggled port respectively
  RCC_APB2ENR= 0x4; // Start clock to GPIO port A

  GPIOA_CRH = 0x119; 	// PA8 alternative function push pull 10MHz (MCO)
  	  	  	  	  	  	// PA9 GPIO output 10Mhz
  	  	  	  	  	  	// PA10 GPIO output 10Mhz

  //Set the Clock config register to output High Speed Internal 8MHz clock at MCO pin 29
  RCC_CFGR=0x5000000;

  // Now pulse pin PA9 and PA10 in a loop. i=80000 is about 1sec
  int i=0;
  int j=99;

  while(1) //
  {
	  GPIOA_BSRR=0x4000200; // Set PA9, clear PA10
	  for (i=0;i<0x80000;i++);
	  GPIOA_BSRR=0x2000400; // Clear PA9, set PA10
	  for (i=0;i<0x80000;i++);

      }

}
