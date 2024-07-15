/*
 * ADC_program.c
 *
 * Created: 9/6/2021 2:56:14 AM
 *  Author: karim hassan
 */ 



#include "BIT_MATH.h"
#include "stdtypes.h"

#include "ADC_private.h"
#include "ADC_interface.h"
#include "ADC_config.h"


void MADC_voidInitialize(void)
{

	/*select reference voltage*/
	switch(REF_VOLT)
	{
		case AVCC:
		SET_BIT(ADMUX , ADMUX_REFS0);
		CLR_BIT(ADMUX , ADMUX_REFS1);
		break;

		case AREF:
		CLR_BIT(ADMUX , ADMUX_REFS0);
		CLR_BIT(ADMUX , ADMUX_REFS1);
		break;

		case INTER:
		SET_BIT(ADMUX , ADMUX_REFS0);
		SET_BIT(ADMUX , ADMUX_REFS1);
		break;

	}

	/*right adjust result*/
	CLR_BIT(ADMUX , ADMUX_ALDAR);

	/*ADC enable*/
	SET_BIT(ADCSRA , ADCSRA_ADEN);

	/*ADC prescaler*/
	switch(DIV_FACTOR)
	{
		case ADC_PRESCALER_2 :
		CLR_BIT(ADCSRA , ADCSRA_ADPS0);
		CLR_BIT(ADCSRA , ADCSRA_ADPS1);
		CLR_BIT(ADCSRA , ADCSRA_ADPS2);
		break;

		case ADC_PRESCALER_4:
		CLR_BIT(ADCSRA , ADCSRA_ADPS0);
		SET_BIT(ADCSRA , ADCSRA_ADPS1);
		CLR_BIT(ADCSRA , ADCSRA_ADPS2);
		break;

		case ADC_PRESCALER_8:
		SET_BIT(ADCSRA , ADCSRA_ADPS0);
		SET_BIT(ADCSRA , ADCSRA_ADPS1);
		CLR_BIT(ADCSRA , ADCSRA_ADPS2);
		break;

		case ADC_PRESCALER_16:
		CLR_BIT(ADCSRA , ADCSRA_ADPS0);
		CLR_BIT(ADCSRA , ADCSRA_ADPS1);
		SET_BIT(ADCSRA , ADCSRA_ADPS2);
		break;

		case ADC_PRESCALER_32:
		SET_BIT(ADCSRA , ADCSRA_ADPS0);
		CLR_BIT(ADCSRA , ADCSRA_ADPS1);
		SET_BIT(ADCSRA , ADCSRA_ADPS2);
		break;

		case ADC_PRESCALER_64:
		CLR_BIT(ADCSRA , ADCSRA_ADPS0);
		SET_BIT(ADCSRA , ADCSRA_ADPS1);
		SET_BIT(ADCSRA , ADCSRA_ADPS2);
		break;

		case ADC_PRESCALER_128:
		SET_BIT(ADCSRA , ADCSRA_ADPS0);
		SET_BIT(ADCSRA , ADCSRA_ADPS1);
		SET_BIT(ADCSRA , ADCSRA_ADPS2);
		break;


	}


}





u8 MADC_u8Get_ChannelReadingSync(u8 Copy_u8ADCPin)
{

	/*clear mux bits*/
	ADMUX &= 0b11100000;

	/*put channel into mux bits*/
	ADMUX |= Copy_u8ADCPin;

	/*ADC start conversion*/
	SET_BIT(ADCSRA , ADCSRA_ADSC);

	/*polling (busy wait)*/
	while(GET_BIT(ADCSRA , ADCSRA_ADIF) == 0);

	/*clear conversion complete flag bit by logical one*/
	SET_BIT(ADCSRA , ADCSRA_ADIF);

	/*return reading value*/
	return ADC_DATA;
}



