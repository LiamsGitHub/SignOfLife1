 /******************************************************************************
 *	Bare minimum startup for STM32F100C8
 *	Cuts every corner possible
 *  Targets Eclipse Kepler with ARM GNU tools gcc-arm-none-eabi-4_8-2013q4
 *	Liam Goudge. July 2014
 *
 *******************************************************************************/

.section  .vectors

vectors:
			.word _stack
			.word main


.end
