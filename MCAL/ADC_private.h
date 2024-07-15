/*
 * ADC_private.h
 *
 * Created: 9/6/2021 2:54:57 AM
 *  Author: karim hassan
 */ 


#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#define ADMUX         *((volatile u8*) 0x27) //ADC multiplexer selection register
#define ADMUX_REFS1   7                      //reference selection bit1
#define ADMUX_REFS0   6                      //reference selection bit1
#define ADMUX_ALDAR   5                      //left adjust result


#define ADCSRA             *((volatile u8*) 0x26) //ADC control and status register
#define ADCSRA_ADEN        7                      //ADC enable
#define ADCSRA_ADSC        6                      //start conversion
#define ADCSRA_ADATE       5                      //Auto trigger enable
#define ADCSRA_ADIF        4                      //interrupt flag
#define ADCSRA_ADIE        3                      //interrupt enable
#define ADCSRA_ADPS2       2                      //prescaler bit2
#define ADCSRA_ADPS1       1                      //prescaler bit1
#define ADCSRA_ADPS0       0                      //prescaler bit0


#define ADCH        *((volatile u8*) 0x25)


#define ADCL        *((volatile u8*) 0x24)

#define ADC_DATA   *((volatile u16*) 0x24)


#endif /* ADC_PRIVATE_H_ */