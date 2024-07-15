/*
 * LED_program.c
 *
 * Created: 9/6/2021 2:58:16 AM
 *  Author: karim hassan
 */ 


#include "DIO_interface.h"
#include "LED_interface.h"
#include "stdtypes.h"



void HLED_voidInitializeLed(u8 copy_u8portTd , u8 copy_u8pinId , u8 copy_u8pinDirection)
{
	MDIO_voidSetPinDirection(copy_u8portTd ,  copy_u8pinId ,  copy_u8pinDirection);
}




void HLED_voidLedOn(u8 copy_u8portTd , u8 copy_u8pinId)
{
	MDIO_voidSetPinValue(copy_u8portTd , copy_u8pinId , HIGH);
}




void HLED_voidLedOff(u8 copy_u8portTd , u8 copy_u8pinId)
{
	MDIO_voidSetPinValue(copy_u8portTd , copy_u8pinId , LOW);
}



void HLED_voidLedToggle(u8 copy_u8portTd , u8 copy_u8pinId)
{
	MDIO_voidTogglePinValue(copy_u8portTd , copy_u8pinId);
}



void HLED_voidLedsOfPortOn(u8 copy_u8portTd)
{
	MDIO_voidSetPortDirection(copy_u8portTd , OUTPUT);
	MDIO_voidSetPortValue(copy_u8portTd , HIGH);
}



void HLED_voidLedsOfPortOff(u8 copy_u8portTd)
{
	MDIO_voidSetPortDirection(copy_u8portTd , OUTPUT);
	MDIO_voidSetPortValue(copy_u8portTd , LOW);
}



void HLED_voidLedsOfportToggle(u8 copy_u8portTd)
{
	MDIO_voidSetPortDirection(copy_u8portTd , OUTPUT);
	MDIO_voidTogglePortValue(copy_u8portTd);
}



