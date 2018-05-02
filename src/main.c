#include "atmega88.h"
#include <inttypes.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>

//Iterrupt vector labels are located in iomx8.h

//ISR (TIMER1_OVF_vect){}


void main (void){
	uint8_t index = 0;
	DDRD |= 0x40;

	while(1){
	    index++;
	    PORTD ^= 0x40;
	}
	
}
