# Project Name
NAME=SignOfLife1

################### File Locations #####################
ROOTDIR = ~/Eclipse
TOOLS = $(ROOTDIR)/gcc-arm-none-eabi-5_2-2015q4/bin/

CC=		$(TOOLS)arm-none-eabi-gcc
NM =	$(TOOLS)arm-none-eabi-nm			# generate symbol table
OD=		$(TOOLS)arm-none-eabi-objdump
AS =	$(TOOLS)arm-none-eabi-as
SZ =	$(TOOLS)arm-none-eabi-size
OC =	$(TOOLS)arm-none-eabi-objcopy

# Other Stuff
ODFLAGS = -h --syms -S
OCFLAGS = -O ihex 
OCFLAGS2 = --change-address 0xE0000 -O ihex example.o example.hex

################### Build Steps #####################

all:
	$(CC) -v -mcpu=cortex-m3 -mthumb -g -nostartfiles -T STM32F100C8_simple.ld  main.c  StartUp_simple.s -o $(NAME).elf
	$(NM) $(NAME).elf
	
	@ echo " "	
	@ echo "List file generation:"
	$(OD) $(ODFLAGS) $(NAME).elf > $(NAME).lst
		
	@ echo " "
	@ echo "Executable size:"
	$(SZ) $(NAME).elf

clean:
	@ echo "Clean up"
	/bin/rm -f *.o *.elf *.lst
	

	
	