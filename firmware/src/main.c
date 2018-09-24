#include <avr/boot.h>
#include <avr/io.h>
#include <avr/power.h>

int adc_read()
{
	
}


void main (void)
{

	// clear the power deduction bit for the ADC
	PRR   ^= 0x01;  // unset PRADC
	ADMUX  = 0x41;  // select external ref, and read from PA1
	ADCSRA = 0x80;  // enable the ADC on port A
	
}
