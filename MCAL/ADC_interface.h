/*
 * ADC_interface.h
 *
 * Created: 9/6/2021 2:55:39 AM
 *  Author: karim hassan
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#include "STDTYPES.h"

void MADC_voidInitialize(void);

u8 MADC_u8Get_ChannelReadingSync(u8 Copy_u8ADCPin);


#endif /* ADC_INTERFACE_H_ */