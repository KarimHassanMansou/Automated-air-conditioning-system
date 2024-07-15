/*
 * ADC_config.h
 *
 * Created: 9/6/2021 2:55:17 AM
 *  Author: karim hassan
 */ 


#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_


#define AVCC  0
#define AREF  1
#define INTER 2

#define ADC_PRESCALER_2    0
#define ADC_PRESCALER_4    1
#define ADC_PRESCALER_8    2
#define ADC_PRESCALER_16   3
#define ADC_PRESCALER_32   4
#define ADC_PRESCALER_64   5
#define ADC_PRESCALER_128  6


#define REF_VOLT     AVCC

#define DIV_FACTOR   ADC_PRESCALER_128

#define ADC_PORT     PORTA_REG
#define ADC0         PIN0
#define ADC1         PIN1
#define ADC2         PIN2
#define ADC3         PIN3
#define ADC4         PIN4
#define ADC5         PIN5
#define ADC6         PIN6
#define ADC7         PIN7




#endif /* ADC_CONFIG_H_ */