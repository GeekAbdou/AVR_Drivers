/*
 * Timers.c
 *
 * Created: 3/24/2020 4:46:03 PM
 *  Author: AbdElrahman
 */ 

 #include "..\Macros\typedef.h"
 #include "Timers.h"

 struct STimer0_Settings Timer0_Configuration;
 uint8_t TOV_Number ;

 static void (*Ptr_To_OVFI)(void);
 static void (*Ptr_To_OCMI)(void);


 extern void TMR0_Init(struct STimer0_Settings Configuration)
 {
	 Timer0_Configuration = Configuration ;

	 /*********************Adjust Mode***********************/
	 if (Timer0_Configuration.Timer0_Mode == NORMAL )
	 {
		 TCCR0 &= ~(1<<WGM00);
		 TCCR0 &= ~( 1<< WGM01);
	 }

	 if (Timer0_Configuration.Timer0_Mode == CTC )
	 {
		 TCCR0 &= ~(1<<WGM00);
		 TCCR0 |= ( 1<< WGM01);
	 }

	 /************************Adjust prescalar************************/
	 TCCR0 = TCCR0 | Timer0_Configuration.Timer0_PRESCALAR;

	 /**************************TMR0 Enable/Disable********************/
	 if (Timer0_Configuration.Timer0_OVFI == TOIE0_enable )
	 {
		 TIMSK |= 1<< TOIE0 ;
	 }
	 else if (Timer0_Configuration.Timer0_OVFI == TOIE0_disable)
	 {
		 TIMSK &= ~(1<< TOIE0) ;

	 }

	 /**************************OCR0 Enable/Disable********************/
	 if (Timer0_Configuration.Timer0_OCIE == OCIE0_enable )
	 {
		 TIMSK |= 1<< OCIE0 ;
	 }
	 else if (Timer0_Configuration.Timer0_OCIE == OCIE0_disable)
	 {
		 TIMSK &= ~(1<< OCIE0) ;

	 }

 }

 extern void TMR0_ReadCounterValue(uint8_t *uint8_tNumOfTicks)
 {
	 *uint8_tNumOfTicks = TCNT0;
 }
 extern void TMR0_Set_Compare_Value(uint8_t uint8_tVal)
 {
	 OCR0 = uint8_tVal;
 }

 extern void TMR0_Set_Counter_Value(uint8_t uint8_tVal)
 {
	 TCNT0 = uint8_tVal;

 }


 //used for set the Number of OverFlow (Used for SW Counters)

 extern void TMR0_Set_TOV_Number(uint8_t uint8_tVal)
 {
	 TOV_Number = uint8_tVal;

 }
 extern void TMR0_Get_TOV_Number(uint8_t *uint8_tVal)
 {
	 *uint8_tVal = TOV_Number ;
 }


 extern void TMR0_Get_Ticks_of_SWcounter (uint32_t *uint8_tVal)
 {
	 *uint8_tVal =  256*TOV_Number + TCNT0;
 }



 extern void callback_TMR0_Overflow_Interrupt (void(*Ptr_to_OVI_Function)(void))
 {
	 Ptr_To_OVFI = Ptr_to_OVI_Function ;

 }
 extern void callback_OCR0_Compare_Match_Interrupt(void(*Ptr_to_OCM_Function)(void))
 {
	 Ptr_To_OCMI = Ptr_to_OCM_Function ;
 }



 ISR(__vector_10)
 {
	 (*Ptr_To_OCMI)();
 }
 
 ISR(__vector_11)
 {
	 TOV_Number++;
	 (*Ptr_To_OVFI)();
 }
 