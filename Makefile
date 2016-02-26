# Project Name
NAME=SignOfLife

################### File Locations #####################
include filePath

CC=		$(PATH)arm-none-eabi-gcc
NM =	$(PATH)arm-none-eabi-nm			# generate symbol table
OD=		$(PATH)arm-none-eabi-objdump
AS =	$(PATH)arm-none-eabi-as
SZ =	$(PATH)arm-none-eabi-size

# Other Stuff
ODFLAGS = -h --syms -S

################### Build Steps #####################

all:
	@ echo "path="$(PATH)
	$(PATH)arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -g -nostartfiles -T STM32F100C8_complexer.ld  main.c  StartUp_simple.s -o $(NAME).elf
	$(PATH)arm-none-eabi-nm $(NAME).elf
	
	@ echo " "	
	@ echo "List file generation:"
	$(OD) $(ODFLAGS) $(NAME).elf > $(NAME).lst
		
	@ echo " "
	@ echo "Executable size:"
	$(SZ) $(NAME).elf

clean:
	@ echo "Clean up"
	/bin/rm -f *.o *.elf *.lst
	

	
	