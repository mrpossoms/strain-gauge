#include <avr/boot.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/power.h>

#define USI_STR _VECTOR(16)
#define USI_OVF _VECTOR(17)

void i2c_init()
{
	USICR =  0x0;  // reset
	USICR |= 0xc0; // enable start condition and count interrupts
	USICR |= 0x03; // enable 2-wire mode using SCL and SDA
	
}

// I2C Start condition interrupt handler
ISR(USI_STR)
{
	// TODO
}

void adc_init()
{
	// clear the power deduction bit for the ADC
	PRR   ^= 0x01;  // unset PRADC
	ADMUX  = 0x41;  // select external ref, and read from PA1
	ADCSRA = 0x80;  // enable the ADC on port A
}


int16_t adc_read()
{
	ADCSRA |= 0x40;       // set the ADSC (bit 6) to start a conversion
	while(ADCSRA & 0x40); // wait for the conversion to finish

	return (ADCH << 8) | ADCL;
}


void main (void)
{
	adc_init();

}
