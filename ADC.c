/*
 * ADC.c
 *
 * Created: 2/7/2021 11:23:35 AM
 *  Author: LENOVO
 */ 
#include <avr/io.h>
#define F_CPU 16000000ul
#include <util/delay.h>
#include "_inpuT_output.h"
#include <avr/interrupt.h>
#include "ADC.h"
void Voltage_Reference_Selections(char votage_refrance)
{
	if (votage_refrance==0)
	{
		ADMUX&=~((1<<REFS0)|(1<<REFS1));
	}
	else if (votage_refrance==1)
	{
		ADMUX|=(1<<REFS0);
		ADMUX&=~(1<<REFS1);
	}
	else if (votage_refrance==2)
	{
		ADMUX|=(1<<REFS0)|(1<<REFS1);
	}
}
void Single_Ended_Input(char channel)
{
	
	switch(channel)
	{
		case 0:
		ADMUX&=~((1<<MUX0)|(1<<MUX1)|(1<<MUX2)|(1<<MUX3)|(1<<MUX4));
		break;
		case 1:
		ADMUX=0b00001;
		break;
		case 2:
		ADMUX&=~((1<<MUX0)|(1<<MUX2)|(1<<MUX3)|(1<<MUX4));
		ADMUX|=(1<<MUX1);
		break;
		case 3:
		ADMUX=0b00011;
		break;
		case 4:
		ADMUX=0b00100;
		break;
		case 5:
		ADMUX=0b00101;
		break;
		case 6:
		ADMUX=0b00110;
		break;
		case 7:
		ADMUX=0b00111;
		break;
	}
	
}
void Prescaler(void)
{
	//devision factor(16000000/128)-->clock 
	ADCSRA &= ~((1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0));
	ADCSRA|=(1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2);
}
void START_CONVERSION(void)
{
	ADCSRA|=(1<<ADSC);
}
void wait_conversion(void)
{
	while(!(ADCSRA&(1<<ADIF)));
}
int read_data(void)
{
	int result=ADCL;
	result|=(ADCH<<8);
	return result;
}

void initial(char channel,char votage_refrance)
{
	ADMUX=(ADMUX&0XE0);
	Single_Ended_Input(channel);
	ADCSRA|=(1<<ADEN); // Enable ADC
	Voltage_Reference_Selections(votage_refrance);
	
	Prescaler();
	
}
