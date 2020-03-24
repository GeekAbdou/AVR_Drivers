/*
 * AVR_GPIO.h
 *
 * Created: 2/13/2019 12:11:03 AM
 *  Author: Abd-Elrahman Elsayed
 * Important Note !! Base is PIN register In your AVR micro controller
 */ 


#ifndef GPIO_H_
#define GPIO_H_

void PinSet(char base , char bin);
void PinReset(char base , char bin);

void PinDirection(char base , char bin , char state); //Control one pin as "input" OR "output"
char PinRead(char base , char bin ); //Reads a pin value in a port
void PinWrite(char base , char bin , char value);//write a value in one pin in a port



void PortDirection(char base , char state); //Control All Port as Input OR Output
char PortRead(char base); //Reads All Port pins Values
void PortWrite(char base , char value); //write A value on all the port pins





#endif /*GPIO_H_*/