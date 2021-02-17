/*
 * GccApplication1.c
 *
 * Created: 1/10/2021 1:57:50 PM
 * Author : LENOVO
 */ 


#include <avr/io.h>
#define F_CPU 16000000ul
#include <util/delay.h>
#include "_inpuT_output.h"
#include "extrnal_inturrpt.h"
//#include "lcd_4bit.h"
#include <avr/interrupt.h>
#include "ADC.h"
#include "TIMER0.h"
ISR(TIMER0_COMP_vect)
{
	
	
	

	
	
}





int main(void)
{
	initi_timer0(FPWM,clock_1024,set_fpwm );
	DDRD|=(1<<7);
	DDRB|=(1<<3);
	OCR0=5.61;
	
	//sei();

    while (1) 
    { 
		
	}
}



