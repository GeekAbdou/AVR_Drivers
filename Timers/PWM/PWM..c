/*
 * PWM.c
 *
 * Created: 3/24/2020 4:46:49 PM
 *  Author: AbdElrahman
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdbool.h>
#include "PWM.h"
void InitPWM()
{ 
	TCCR0A |= (1 << COM0A1); // set none-inverting mode
	TCCR0A |= (1 << WGM01) | (1 << WGM00); // set fast PWM Mode
	TCCR0B |= (1 << CS02) | (1 << CS00) ; // set prescaler to 128 and starts PWM
}

void SetPWM(uint8_t duty)
{
 OCR0A = duty;
}
