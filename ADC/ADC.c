/*
 * ADC.c
 *
 * Created: 3/24/2020 4:44:00 PM
 *  Author: AbdElrahman
 */ 
#include <avr/io.h>
#include "ADC.h"


void InitADC(void)
{
	ADMUX = (1 >> REFS0)  | (1 << MUX0) | (1 << MUX2); ;
	/*
	 REFS1:REFS0 = 0 : 0 AREF, Internal Vref turned off
				 = 0 : 1 AVCC with external capacitor at AREF pin
				 = 1 : 0 Reserved //Not Allowed
				 = 1 : 1 Internal 1.1V Voltage Reference with external capacitor at AREF pin
	 ADLAR = 0 right adjusted  0000 00XX       XXXX XXXX //Default (Prefared)
	 ADLAR = 1 LEFT adjusted   XXXX XXXX       XX00 0000
	 */

	ADCSRA = (1 << ADEN) | (1 << ADIE) | (1 << ADPS0) | (1 << ADPS1) | (1 << ADPS2);
	/*
	ADCSRA register
	ADEN(Bit 7)=1 to enable ADC,

	ADPS2		ADPS1		 ADPS0		 Division Factor
	  0			 0			  0				 2
	  0			 0		   	  1				 2
	  0			 1			  0				 4
	  0			 1			  1				 8
	  1			 0			  0				 16
	  1			 0			  1				 32
	  1			 1			  0				 64
	  1			 1			  1				 128
	*/

}

 

unsigned short ADCRead(uint8_t channel_num)
{	channel_num &= 0x07;//must be from 0>>7 to select one of these pin ADC0,1,2 to provide negitaive value
	//ADMUX &= 0xE0; //to clear from MUX4 to MUX0 before set the required bit
	ADMUX |= channel_num; //choose the correct channel by setting the channel number in MUX4:0 bits
	ADCSRA |= (1<<ADSC); //to start the conversion by set Bit (ADSC)
	while( !(ADCSRA & (1<<4) ) ); //wait for the conversion to complete and ADIF(Bit 4) become 1
	ADCSRA |= (1<<4); //clear ADIF by write'1' to it 
	return ADC; //combine ADCL + ADCH
}


