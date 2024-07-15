/*
 * Temprature_sensor.c
 *
 * Created: 9/6/2021 2:53:12 AM
 *  Author: karim hassan
 */ 



#include <util/delay.h>
#include "ADC_interface.h"
#include "ADC_config.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "LED_interface.h"
#include "BIT_MATH.h"
#include "STDTYPES.h"


int main(void)
{
	
	u8 Global_copy_u8READ;
	u16 Global_Copy_u16Analog;
	u16 Global_Copy_u16Temp;
	
	MADC_voidInitialize();
	HLCD_voidInitialize();
	
	MDIO_voidSetPinDirection(PORTA , PIN0 , INPUT);//ADC PIN0
	
	MDIO_voidSetPinDirection(PORTB , PIN0 , OUTPUT);//heater
	MDIO_voidSetPinDirection(PORTD , PIN4 , OUTPUT);//DC motor cooler
	
	MDIO_voidSetPinDirection(PORTD , PIN3 , OUTPUT);//Blue LED
	MDIO_voidSetPinDirection(PORTB , PIN7 , OUTPUT);//Red LED
	
	MDIO_voidSetPinDirection(PORTD , PIN7 , OUTPUT);//Green LED
	
	HLCD_voidSendString(" Temperature:");
	
    while(1)
    {
		
		 Global_copy_u8READ = MADC_u8Get_ChannelReadingSync(PIN0);
		  
		 Global_Copy_u16Analog = (u16)((u32)(Global_copy_u8READ * 5000UL) /1024UL);
		 
		 Global_Copy_u16Temp = ((Global_Copy_u16Analog) / 10UL);
		 
		
		 if(Global_Copy_u16Temp < 100)
		 {
			 
		     HLCD_voidGoTo(1 , 12);//POS
			 HLCD_voidSendData((Global_Copy_u16Temp/10)+48);
			 HLCD_voidSendData((Global_Copy_u16Temp%10)+48);
			 HLCD_voidSendData(0XDF);//dot before C
			 HLCD_voidSendString("C");
			 HLCD_voidSendCommand(0xC0);//next line in LCD
			
			  if(Global_Copy_u16Temp > 30)
			  {
				  
				  HLCD_voidSendString("Cooler mode");
				  HLCD_voidSendCommand(0xF0);
				 
				  MDIO_voidSetPinValue(PORTD , PIN4 , HIGH);//cooler
				  
				  HLED_voidLedOn(PORTD , PIN3);//blue led
				  HLED_voidLedOff(PORTD , PIN7);//Green led
				  
			  }
			  else if (Global_Copy_u16Temp < 20)
			  {
			
				  HLCD_voidSendString("Heater mode   ");  
				  HLCD_voidSendCommand(0xF0);
				  
				  MDIO_voidSetPinValue(PORTB , PIN0 , HIGH);//heater
				  
				  HLED_voidLedOn(PORTB , PIN7);//red led
				  HLED_voidLedOff(PORTD , PIN7);//Green led
				  
			  }
			  else if(Global_Copy_u16Temp <= 30 && Global_Copy_u16Temp >= 20)
			  {
				  
				  HLCD_voidSendString("Normal mode   "); 
				  HLCD_voidSendCommand(0xF0);
				
				  MDIO_voidSetPinValue(PORTB , PIN0 , LOW);//Heater
				  MDIO_voidSetPinValue(PORTD , PIN4 , LOW);//cooler
				  
				  HLED_voidLedOff(PORTD , PIN3);//Blue led
				  HLED_voidLedOff(PORTB , PIN7);//Red led
				  HLED_voidLedOn(PORTD , PIN7);//Green led
				  
			  }
			  else
			  {
				  
			  }
			  
		 }			 
		 else
		 {
			 
		 }
		 
		 _delay_ms(1000);
		
		
    }
	
	
}


