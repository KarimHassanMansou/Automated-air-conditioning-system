/*
 * LCD_interface.h
 *
 * Created: 9/6/2021 2:59:09 AM
 *  Author: karim hassan
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#include "STDTYPES.h"

void HLCD_voidInitialize(void);
void HLCD_voidSendCommand(unsigned char copy_u8Command);
void HLCD_voidSendData(unsigned char copy_u8Data);
void HLCD_voidSendString(unsigned char *ptr_u8Str);
void HLCD_voidClearLCD(void);
void HLCD_voidGoTo(unsigned char line  , unsigned char pos);
void HLCD_voidWriteNumber(u16 copy_intNumber);



#endif /* LCD_INTERFACE_H_ */