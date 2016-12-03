
/* Memory configuration for STM32F100C8 simplified version */
/* Liam Goudge. July 2014 */

ENTRY(main)

MEMORY
{
	FLASH (rx)  : ORIGIN = 0x00000000, LENGTH = 64K
  	SRAM (rw) 	: ORIGIN = 0x20000000, LENGTH = 8K
  	STACK (rw)	: ORIGIN = 0x20002000, LENGTH = 0K
}

PROVIDE (_stack = ORIGIN(STACK));

SECTIONS
{
 .text : {
 			*(.vectors)
 			*(.text)
 		}
}

