// Header file for STM32F100 peripheral set

// Reset and Clock Control (RCC)

#define RCC_CR            (*((volatile unsigned long *) 0x40021000)) // Clock Control register. Offset=0x0
#define RCC_CFGR          (*((volatile unsigned long *) 0x40021004)) // Clock configuration register. Offset=0x4
#define RCC_APB1ENR       (*((volatile unsigned long *) 0x4002101C)) // APB1 peripheral clock enable register. Offset=0x1C
#define RCC_APB2ENR       (*((volatile unsigned long *) 0x40021018)) // APB2 peripheral clock enable register. Offset=0x18

// GPIO Port Registers
// GPIO Port A
#define GPIOA_CRL         (*((volatile unsigned long *) 0x40010800)) // GPIO port A. Port configuration register low. Offset=0x0
#define GPIOA_CRH         (*((volatile unsigned long *) 0x40010804)) // GPIO port A. Port configuration register High. Offset=0x4
#define GPIOA_BSRR        (*((volatile unsigned long *) 0x40010810)) // GPIO port A. Bit set/reset register. Offset = 0x10


// ADC1 Registers
// Base = 0x4001 2400
#define ADC_SR             (*((volatile unsigned long *) 0x40012400)) // ADC Status Register. Offset = 0x0
#define ADC_CR2            (*((volatile unsigned long *) 0x40012408)) // ADC Control Register 2. Offset = 0x8
#define ADC_SMPR2          (*((volatile unsigned long *) 0x40012410)) // ADC Sample time Register 2. Offset = 0x10
#define ADC_SQR3           (*((volatile unsigned long *) 0x40012434)) // ADC Regular Sequence Register3. Offset = 0x34
#define ADC_DR             (*((volatile unsigned long *) 0x4001244C)) // ADC Regular Data Register. Offset = 0x4C


// DAC Registers
// Base = 0x4000 7400
#define DAC_CR             (*((volatile unsigned long *) 0x40007400)) // Applies to both DAC1 and DAC2. Offset = 0x0
#define DAC_DHR12R1        (*((volatile unsigned long *) 0x40007408)) // DAC1 data holding register for right aligned 12-bit mode. Offset = 0x8
#define DAC_DHR12R2        (*((volatile unsigned long *) 0x40007414)) // DAC2 data holding register for right aligned 12-bit mode. Offset = 0x14
#define DAC_DOR1           (*((volatile unsigned long *) 0x4000742C)) // DAC channel1 data output register. Read-only. Offset = 0x2C
#define DAC_DOR2           (*((volatile unsigned long *) 0x40007430)) // DAC channel2 data output register. Read-only. Offset = 0x30

