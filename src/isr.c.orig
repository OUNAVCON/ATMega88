#include "atmega88.h"


/** \cond DOXYGEN_SHOULD_SKIP_THIS */
extern int main(void);
/** \endcond */

/* Default empty handler */
void Dummy_Handler(void);
void Reset_Handler(void);

/* Exception Table */
__attribute__ ((section(".isrVectors")))
const DeviceVectors exception_table = {
        /* Configure Initial Stack Pointer, using linker-generated symbols */
        (void*) Reset_Handler, /* Reset */
        (void*) Dummy_Handler, /* INT0 */
        (void*) Dummy_Handler, /* INT1 */
        (void*) Dummy_Handler, /* PCINT0 */
        (void*) Dummy_Handler, /* PCINT1 */
        (void*) Dummy_Handler, /* PCINT2 */
        (void*) Dummy_Handler, /* WDT */
        (void*) Dummy_Handler, /* TIMER2_COMPA */
        (void*) Dummy_Handler, /* TIMER2_COMB */
        (void*) Dummy_Handler, /* TIMER2_OVF */
        (void*) Dummy_Handler, /* TIMER1_CAPT */
        (void*) Dummy_Handler, /* TIMER1_COMPA */
        (void*) Dummy_Handler, /* TIMER1_COMB */
        (void*) Dummy_Handler, /* TIMER1_OVF */
        (void*) Dummy_Handler, /* TIMER0_COMPA */
        (void*) Dummy_Handler, /* TIMER0_COMPB */
        (void*) Dummy_Handler, /* TIMER0_OVF */
        (void*) Dummy_Handler, /* SPI_STC */
        (void*) Dummy_Handler, /* USART_RX*/
        (void*) Dummy_Handler, /* USART_UDRE */
        (void*) Dummy_Handler, /* USART_TX */
        (void*) Dummy_Handler, /* ADC */
        (void*) Dummy_Handler, /* EE READY */
        (void*) Dummy_Handler, /* ANALOG COMPARATOR*/
        (void*) Dummy_Handler, /* TWI - I2C */
        (void*) Dummy_Handler  /* SPM_READY */
};

/**
 * \brief This is the code that gets called on processor reset.
 * To initialize the device, and call the main() routine.
 */
void Reset_Handler(void)
{
	//See what went wrong...
	main();
}
/**
 * \brief Default interrupt handler for unused IRQs.
 */
void Dummy_Handler(void)
{
	int i = 0;
        while (1) {
	 i++;
        }
}

