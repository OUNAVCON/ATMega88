

/*@}*/
typedef struct _DeviceVectors
{
  void* pfnReset_Handler;                     /* 0  Reset */
  void* pfnINT0_Handler;                      /*  1 INT0 */
  void* pfnINT1_Handler;                      /*  2 INT1 */
  void* pfnPCINT0_Handler;                    /*  3 PC INT0 */
  void* pfnPCINT1_Handler;                    /*  4 PC INT1 */
  void* pfnPCINT2_Handler;                    /*  5 PC INT2 */
  void* pfnWDT_Handler;                       /*  6 WDT */
  void* pfnTIMER2_COMPA_Handler;              /*  7 TIMER2_COMPA */
  void* pfnTIMER2_COMPB_Handler;              /*  8 TIMER2_COMB */
  void* pfnTIMER2_OVF_Handler;                /*  9 TIMER2_OVF */
  void* pfnTIMER1_CAPT_Handler;               /* 10 TIMER1_CAPT  */
  void* pfnTIMER1_COMPA_Handler;              /* 11 TIMER1_COMPA */
  void* pfnTIMER1_COMB_Handler;               /* 12 TIMER1_COMB */
  void* pfnTIMER1_OVF_Handler;                /* 13 TIMER1_OVF*/
  void* pfnTIMER0_COMPA_Handler;              /* 14 TIMER0_COMPA */
  void* pfnTIMER0_COMPB_Handler;              /* 15 TIMER0_COMPB */
  void* pfnTIMER0_OVF_Handler;                /* 16 TIMER0_OVF */
  void* pfnSPI_STC_Handler;                   /* 17 SPI_STC */
  void* pfnSPI_RX_Handler;                   /* 18 USART_RX */
  void* pfnUSART_UDRE_Handler;             /* 19 USART_UDRE  */
  void* pfnUSART_TX_Handler;                  /* 20 USART_TX */
  void* pfnADC_Handler;                       /* 21 ADC */
  void* pfnEE_READY_Handler;                  /* 23 EE READY */
  void* pfnANALOG_COMPARATOR_Handler;         /* 24 ANALOG COMPARATOR* */
  void* pfnTWI_Handler;                       /* 25 TWI I2C* */
  void* pfnSPM_READY_Handler;                 /* 26 SPM READY */
} DeviceVectors;



#define BASE 0x00 //End Address = 0xFF
#define PINB   (*((volatile uint8_t *)(BASE+0x23)))
#define DDRB   (*((volatile uint8_t *)(BASE+0x24)))
#define PORTB  (*((volatile uint8_t *)(BASE+0x25)))
#define PINC   (*((volatile uint8_t *)(BASE+0x26)))
#define DDRC   (*((volatile uint8_t *)(BASE+0x27)))
#define PORTC  (*((volatile uint8_t *)(BASE+0x28)))
#define PIND   (*((volatile uint8_t *)(BASE+0x29)))
#define DDRD   (*((volatile uint8_t *)(BASE+0x2A)))
#define PORTD  (*((volatile uint8_t *)(BASE+0x2B)))
#define TIFR0  (*((volatile uint8_t *)(BASE+0x35)))
#define TIFR1  (*((volatile uint8_t *)(BASE+0x36)))
#define TIFR2  (*((volatile uint8_t *)(BASE+0x37)))
#define PCIFR  (*((volatile uint8_t *)(BASE+0x3B)))
#define EIFR   (*((volatile uint8_t *)(BASE+0x3C)))
#define EIMSK  (*((volatile uint8_t *)(BASE+0x3D)))
#define GPIOR0 (*((volatile uint8_t *)(BASE+0x3E)))
#define EECR   (*((volatile uint8_t *)(BASE+0x3F)))
#define EEDR   (*((volatile uint8_t *)(BASE+0x40)))
#define EEDRL  (*((volatile uint8_t *)(BASE+0x41)))
#define EEDRH  (*((volatile uint8_t *)(BASE+0x42)))
#define GTCCR  (*((volatile uint8_t *)(BASE+0x43)))
#define TCCR0A (*((volatile uint8_t *)(BASE+0x44)))
#define TCCR0B (*((volatile uint8_t *)(BASE+0x45)))
#define TCNT0  (*((volatile uint8_t *)(BASE+0x46)))
#define OCR0A  (*((volatile uint8_t *)(BASE+0x47)))
#define OCR0B  (*((volatile uint8_t *)(BASE+0x48)))
#define GPIOR1 (*((volatile uint8_t *)(BASE+0x4A)))
#define GPIOR2 (*((volatile uint8_t *)(BASE+0x4B)))
#define SPCR0  (*((volatile uint8_t *)(BASE+0x4C)))
#define SPSR0  (*((volatile uint8_t *)(BASE+0x4D)))
#define SPDR0  (*((volatile uint8_t *)(BASE+0x4E)))
#define ACSR   (*((volatile uint8_t *)(BASE+0x50)))
#define DWDR   (*((volatile uint8_t *)(BASE+0x51)))
#define SMCR   (*((volatile uint8_t *)(BASE+0x53)))
#define MCUSR  (*((volatile uint8_t *)(BASE+0x54)))
#define MCUCR  (*((volatile uint8_t *)(BASE+0x55)))
#define SPMCSR (*((volatile uint8_t *)(BASE+0x57)))
#define SPL    (*((volatile uint8_t *)(BASE+0x5D)))
#define SPH    (*((volatile uint8_t *)(BASE+0x5E)))
#define SREG   (*((volatile uint8_t *)(BASE+0x5F)))
#define WDTCSR (*((volatile uint8_t *)(BASE+0x60)))
#define CLKPR  (*((volatile uint8_t *)(BASE+0x60)))
#define PRR    (*((volatile uint8_t *)(BASE+0x64)))
#define OSCCAL (*((volatile uint8_t *)(BASE+0x66)))
#define PCICR  (*((volatile uint8_t *)(BASE+0x68)))
#define EICRA  (*((volatile uint8_t *)(BASE+0x69)))
#define PCMSK0 (*((volatile uint8_t *)(BASE+0x6B)))
#define PCMSK1 (*((volatile uint8_t *)(BASE+0x6C)))
#define PCMSK2 (*((volatile uint8_t *)(BASE+0x6D)))
#define TIMSK0 (*((volatile uint8_t *)(BASE+0x6E)))
#define TIMSK1 (*((volatile uint8_t *)(BASE+0x6F)))
#define TIMSK2 (*((volatile uint8_t *)(BASE+0x70)))
#define ADCL   (*((volatile uint8_t *)(BASE+0x78)))
#define ADCH   (*((volatile uint8_t *)(BASE+0x79)))
#define ADCSRA (*((volatile uint8_t *)(BASE+0x7A)))
#define ADCSRB (*((volatile uint8_t *)(BASE+0x7B)))
#define ADMUX  (*((volatile uint8_t *)(BASE+0x7C)))
#define DIDR0  (*((volatile uint8_t *)(BASE+0x7E)))
#define DIDR1  (*((volatile uint8_t *)(BASE+0x7F)))
#define TCCR1A (*((volatile uint8_t *)(BASE+0x80)))
#define TCCR1B (*((volatile uint8_t *)(BASE+0x81)))
#define TCCR1C (*((volatile uint8_t *)(BASE+0x82)))
#define TCNT1L (*((volatile uint8_t *)(BASE+0x84)))
#define TCNT1H (*((volatile uint8_t *)(BASE+0x85)))
#define ICR1L  (*((volatile uint8_t *)(BASE+0x86)))
#define ICR1H  (*((volatile uint8_t *)(BASE+0x87)))
#define OCR1AL (*((volatile uint8_t *)(BASE+0x88)))
#define OCR1AH (*((volatile uint8_t *)(BASE+0x89)))
#define OCR1BL (*((volatile uint8_t *)(BASE+0x8A)))
#define OCR1BH (*((volatile uint8_t *)(BASE+0x8B)))
#define OCR1AH (*((volatile uint8_t *)(BASE+0x89)))
#define TCCR2A (*((volatile uint8_t *)(BASE+0xB0)))
#define TCCR2B (*((volatile uint8_t *)(BASE+0xB1)))
#define TCNT2  (*((volatile uint8_t *)(BASE+0xB2)))
#define PCR2A  (*((volatile uint8_t *)(BASE+0xB3)))
#define PCR2B  (*((volatile uint8_t *)(BASE+0xB4)))
#define ASSR   (*((volatile uint8_t *)(BASE+0xB6)))
#define TWBR   (*((volatile uint8_t *)(BASE+0xB8)))
#define TWSR   (*((volatile uint8_t *)(BASE+0xB9)))
#define TWAR   (*((volatile uint8_t *)(BASE+0xBA)))
#define TWDR   (*((volatile uint8_t *)(BASE+0xBB)))
#define TWCR   (*((volatile uint8_t *)(BASE+0xBC)))
#define TWAMR  (*((volatile uint8_t *)(BASE+0xBD)))
#define UCSR0A (*((volatile uint8_t *)(BASE+0xC0)))
#define UCSR0B (*((volatile uint8_t *)(BASE+0xC1)))
#define UCSR0C (*((volatile uint8_t *)(BASE+0xC2)))
#define UBRR0L (*((volatile uint8_t *)(BASE+0xC4)))
#define UBRR0H (*((volatile uint8_t *)(BASE+0xC5)))
#define UDR0   (*((volatile uint8_t *)(BASE+0xC6)))


