/* Memory configuration for STM32F100C8 simplified version */
/* Liam Goudge. July 2014 */

ENTRY(main)

MEMORY
{
  	SRAM (rwx) 	: ORIGIN = 0x20000000, LENGTH = 8K
  	STACK (rwx)	: ORIGIN = 0x20002000, LENGTH = 0K
  	FLASH (rx)  : ORIGIN = 0x00000000, LENGTH = 64K
}

PROVIDE (_stack = ORIGIN(STACK));

SECTIONS
{
   .text : {
   				*(.vectors)
   				*(.text)
   				}>FLASH
   .data : { *(.data) }
   .bss : { *(.bss) }
}