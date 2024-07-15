/*
 * LCD_program.c
 *
 * Created: 9/6/2021 2:59:33 AM
 *  Author: karim hassan
 */ 


#include "LCD_interface.h"
#include "LCD_config.h"
#include "DIO_interface.h"
#include <string.h>
#include <util/delay.h>


void HLCD_voidSendCommand(unsigned char copy_u8Command)
{
	/*WRITE COMMAND ON DDRAM*/
	MDIO_voidSetPortValue(LCD_DATA_PORT , copy_u8Command);

	/*RS AND RW = 0*/
	MDIO_voidSetPinValue(LCD_CONTROL_PORT , LCD_RS , LOW);//write command
	MDIO_voidSetPinValue(LCD_CONTROL_PORT , LCD_RW , LOW);//write

	/*ENABLE PULSE*/
	MDIO_voidSetPinValue(LCD_CONTROL_PORT , LCD_EN , HIGH);
	_delay_ms(1);//230ns
	MDIO_voidSetPinValue(LCD_CONTROL_PORT , LCD_EN , LOW);

}



void HLCD_voidSendData(unsigned char copy_u8Data)
{
	/*WRITE COMMAND ON DDRAM*/
	MDIO_voidSetPortValue(LCD_DATA_PORT , copy_u8Data);

	/*RS AND RW = 0*/
	MDIO_voidSetPinValue(LCD_CONTROL_PORT , LCD_RS , HIGH);
	MDIO_voidSetPinValue(LCD_CONTROL_PORT , LCD_RW , LOW);

	/*ENABLE PULSE*/
	MDIO_voidSetPinValue(LCD_CONTROL_PORT , LCD_EN , HIGH);
	_delay_ms(1);//230ns
	MDIO_voidSetPinValue(LCD_CONTROL_PORT , LCD_EN , LOW);

}





void HLCD_voidInitialize(void)
{

	MDIO_voidSetPortDirection(LCD_DATA_PORT , OUTPUT);
	MDIO_voidSetPortDirection(LCD_CONTROL_PORT , OUTPUT);

	_delay_ms(100);

	HLCD_voidSendCommand(0x38);
	HLCD_voidSendCommand(0x0F);
	HLCD_voidSendCommand(0x01);

	_delay_ms(2);

	HLCD_voidSendCommand(0x06);

}




void HLCD_voidSendString(unsigned char *ptr_u8Str)
{
	int i=0;

	while(ptr_u8Str[i] != '\0')
	{
		HLCD_voidSendData(ptr_u8Str[i]);
		i++;
	}

}





void HLCD_voidClearLCD()
{
	HLCD_voidSendCommand(0x01);
	HLCD_voidSendString("                ");

}





void HLCD_voidGoTo(u8 line  , u8 pos)/*pos = position in line*/
{

	switch(line)
	{

		case 1:
		HLCD_voidSendCommand(pos + 0x80);//line one
		break;

		case 2:
		HLCD_voidSendCommand(pos + 0xC0);//line two
		break;

	}

}




void HLCD_voidWriteNumber(u16 copy_intNumber)
{
	u8 *character;

	sprintf(character ,"%d" , copy_intNumber);

	HLCD_voidSendString(character);
}




