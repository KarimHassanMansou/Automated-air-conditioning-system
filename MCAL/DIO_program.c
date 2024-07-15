/*
 * DIO_program.c
 *
 * Created: 9/6/2021 2:57:30 AM
 *  Author: karim hassan
 */ 



#include "DIO_interface.h"
#include "DIO_private.h"
#include "STDTYPES.h"



void MDIO_voidSetPortDirection(u8 copy_u8portTd , u8 copy_u8portDirection)
{

	switch(copy_u8portTd)
	{

		case PORTA:
		if(copy_u8portDirection == OUTPUT)
		{
			DDRA_REG = 0xFF;
		}
		else if(copy_u8portDirection == INPUT)
		{
			DDRA_REG = 0x00;
		}
		else
		{

		}
		break;

		case PORTB:
		if(copy_u8portDirection == OUTPUT)
		{
			DDRB_REG = 0xFF;
		}
		else if(copy_u8portDirection == INPUT)
		{
			DDRB_REG = 0x00;
		}
		else
		{

		}
		break;

		case PORTC:

		if(copy_u8portDirection == OUTPUT)
		{
			DDRC_REG = 0xFF;
		}
		else if(copy_u8portDirection == INPUT)
		{
			DDRC_REG = 0x00;
		}
		else
		{

		}
		break;


		case PORTD:
		{
			if(copy_u8portDirection == OUTPUT)
			{
				DDRD_REG = 0xFF;
			}
			else  if(copy_u8portDirection == INPUT)
			{
				DDRD_REG = 0x00;
			}
			else
			{

			}
			break;

			default:

			/*invalid port id*/ break;


		}/**end of switch**/

	}/**end of function**/

}




void MDIO_voidSetPortValue(u8 copy_u8portTd , u8 copy_u8portValue)
{

	switch(copy_u8portTd)
	{

		case PORTA:
		if(copy_u8portValue == HIGH)
		{
			PORTA_REG = 0xFF;
		}
		else if(copy_u8portValue == LOW)
		{
			PORTA_REG = 0;
		}
		else
		{
			PORTA_REG = copy_u8portValue;
		}
		break;

		case PORTB:
		if(copy_u8portValue == HIGH)
		{
			PORTB_REG = 0xFF;
		}
		else if(copy_u8portValue == LOW)
		{
			PORTB_REG = 0;
		}
		else
		{
			PORTB_REG = copy_u8portValue;
		}
		break;

		case PORTC:
		if(copy_u8portValue == HIGH)
		{
			PORTC_REG = 0xFF;
		}
		else if(copy_u8portValue == LOW)
		{
			PORTC_REG = 0;
		}
		else
		{
			PORTC_REG = copy_u8portValue;
		}
		break;


		case PORTD:
		if(copy_u8portValue == HIGH)
		{
			PORTD_REG = 0xFF;
		}
		else if(copy_u8portValue == LOW)
		{
			PORTD_REG = 0;
		}
		else
		{
			PORTD_REG = copy_u8portValue;
		}
		break;

		default: break;



	}/**end of switch**/

}/**end of functions**/




void MDIO_voidTogglePortValue(u8 copy_u8portTd)
{
	switch(copy_u8portTd)
	{
		case PORTA:
		TOG_REG(PORTA_REG);
		break;

		case PORTB:
		TOG_REG(PORTB_REG);
		break;

		case PORTC:
		TOG_REG(PORTC_REG);
		break;

		case PORTD:
		TOG_REG(PORTD_REG);
		break;

	}

}






void MDIO_voidSetPinDirection(u8 copy_u8portTd , u8 copy_u8pinId , u8 copy_u8pinDirection)
{

	switch(copy_u8portTd)
	{
		case PORTA:
		if(copy_u8pinDirection == OUTPUT)
		{
			SET_BIT(DDRA_REG , copy_u8pinId);
		}
		else if(copy_u8pinDirection == INPUT)
		{
			CLR_BIT(DDRA_REG , copy_u8pinId);
		}
		else
		{
			//error
		}
		break;

		case PORTB:
		if(copy_u8pinDirection == OUTPUT)
		{
			SET_BIT(DDRB_REG , copy_u8pinId);
		}
		else if(copy_u8pinDirection == INPUT)
		{
			CLR_BIT(DDRB_REG , copy_u8pinId);
		}
		else
		{
			//error
		}
		break;

		case PORTC:
		if(copy_u8pinDirection == OUTPUT)
		{
			SET_BIT(DDRC_REG , copy_u8pinId);
		}
		else if(copy_u8pinDirection == INPUT)
		{
			CLR_BIT(DDRC_REG , copy_u8pinId);
		}
		else
		{
			//error
		}
		break;

		case PORTD:
		if(copy_u8pinDirection == OUTPUT)
		{
			SET_BIT(DDRD_REG , copy_u8pinId);
		}
		else if(copy_u8pinDirection == INPUT)
		{
			CLR_BIT(DDRD_REG , copy_u8pinId);
		}
		else
		{
			//error
		}
		break;

		default: break;

	}


}




void MDIO_voidSetPinValue(u8 copy_u8portTd , u8 copy_u8pinId , u8 copy_u8portValue)
{

	switch(copy_u8portTd)
	{
		case PORTA:
		if(copy_u8portValue == HIGH)
		{
			SET_BIT(PORTA_REG , copy_u8pinId);
		}
		else if(copy_u8portValue == LOW)
		{
			CLR_BIT(PORTA_REG , copy_u8pinId);
		}
		else
		{
			//error
		}
		break;

		case PORTB:
		if(copy_u8portValue == HIGH)
		{
			SET_BIT(PORTB_REG , copy_u8pinId);
		}
		else if(copy_u8portValue == LOW)
		{
			CLR_BIT(PORTB_REG , copy_u8pinId);
		}
		else
		{
			//error
		}
		break;

		case PORTC:
		if(copy_u8portValue == HIGH)
		{
			SET_BIT(PORTC_REG , copy_u8pinId);
		}
		else if(copy_u8portValue == LOW)
		{
			CLR_BIT(PORTC_REG , copy_u8pinId);
		}
		else
		{
			//error
		}
		break;

		case PORTD:
		if(copy_u8portValue == HIGH)
		{
			SET_BIT(PORTD_REG , copy_u8pinId);
		}
		else if(copy_u8portValue == LOW)
		{
			CLR_BIT(PORTD_REG , copy_u8pinId);
		}
		else
		{
			//error
		}
		break;

		default: break;

	}
}




void MDIO_voidTogglePinValue(u8 copy_u8portTd , u8 copy_u8pinId)
{

	switch(copy_u8portTd)
	{
		case PORTA:
		TOG_BIT(PORTA_REG , copy_u8pinId);
		break;

		case PORTB:
		TOG_BIT(PORTB_REG , copy_u8pinId);
		break;

		case PORTC:
		TOG_BIT(PORTC_REG , copy_u8pinId);
		break;

		case PORTD:
		TOG_BIT(PORTD_REG , copy_u8pinId);
		break;

		default: break;


	}


}




u8 MDIO_u8GetPinValue(u8 copy_u8portTd , u8 copy_u8pinId)
{

	u8 Local_u8pinState;

	switch(copy_u8portTd)
	{
		case PORTA:
		Local_u8pinState = GET_BIT(PINA_REG , copy_u8pinId);
		break;

		case PORTB:
		Local_u8pinState = GET_BIT(PINB_REG , copy_u8pinId);
		break;

		case PORTC:
		Local_u8pinState = GET_BIT(PINC_REG , copy_u8pinId);
		break;

		case PORTD:
		Local_u8pinState = GET_BIT(PIND_REG , copy_u8pinId);
		break;

		default: break;

	}

	return Local_u8pinState;

}


