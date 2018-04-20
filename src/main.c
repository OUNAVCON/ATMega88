#include "atmega88.h"
#include "stdint.h"



void main (void){
	uint8_t index = 0;
	DDRD |= 0x40;

	while(1){
	    index++;
	    PORTD ^= 0x40;
	}
	
}
