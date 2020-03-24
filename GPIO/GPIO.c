/*
 * AVR_GPIO.c
 *
 * Created: 2/13/2019 12:10:42 AM
 *  Author: Abd-Elrahman Elsayed
 */ 
#include "GPIO.h"
#include "..\Macros\ChipPorts.h"
#include "..\Macros\typedef.h"

//For Setting The whole Port pins as Input OR output
void PortDirection(char base , char state)//Base is PIN register and we need to select DDR resister (DDR Controls Input OR Output)
{
	if (state == output) ( *(volatile uint8_t *)(base+1) ) = 0xff;
	else ( *(volatile uint8_t *)(base+1) ) = 0x00;
}

//For Setting A one pin as Input OR Output
void PinDirection(char base ,char bin, char state)//Base is PIN register and we need to select DDR resister (DDR Controls Input OR Output)
{
	if (state == output) ( *(volatile uint8_t *)(base+1) ) |= (1<<bin);
	else ( *(volatile uint8_t *)(base+1) ) &= ~(1<<bin);
}

//For Setting High signal on A pin
void PinSet(char base , char bin)//Base is PIN register and we need to select PORT resister (PORT controls putting High OR low Signals)
{
	(*(volatile uint8_t *)(base+2)) |= (1<<bin);
}

//For Setting Low signal on A pin
void PinReset(char base , char bin)//Base is PIN register and we need to select PORT resister (PORT controls putting High OR low Signals)
{
	(*(volatile uint8_t *)(base+2)) &= ~(1<<bin);
}

//For Setting A Voltage Value on Port of pins
void PortWrite(char base , char value)//Base is PIN register and we need to select PORT resister (PORT controls putting High OR low Signals)
{
	(*(volatile uint8_t *)(base+2)) = value;
}

//For Setting A High OR Low Signal on a pin (the same Bin_Set and Bin_Reset)
void PinWrite(char base , char bin , char value)
{
	if (value == 0) (*(volatile uint8_t *)(base+2)) &= ~(1<<bin);
	else (*(volatile uint8_t *)(base+2)) |= (1<<bin); 
}

//For reading A signal On a PORT
char PortRead(char base)//Base is PIN register and we need to select PIN resister (PIN Reads High OR low Signals)
{
	uint8_t reg_value; 
	reg_value = (*(volatile uint8_t *)(base));
	return reg_value;
}

//For reading A signal On a Bin On Port
char PinRead(char base , char bin )//Base is PIN register and we need to select PIN resister (PIN Reads High OR low Signals)
{
	uint8_t pin_value ;
	pin_value = (*(volatile uint8_t *)(base)) && (1<<bin);
	if (pin_value == 0) return 0;
	else return 1;
}