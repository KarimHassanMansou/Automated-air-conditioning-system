/*
 * LED_interface.h
 *
 * Created: 9/6/2021 2:58:36 AM
 *  Author: karim hassan
 */ 


#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_



/*initialization*/
void HLED_voidInitializeLed(u8 copy_u8portTd , u8 copy_u8pinId , u8 copy_u8pinDirection);

/*separated LEDs*/
void HLED_voidLedOn(u8 copy_u8portTd , u8 copy_u8pinId);
void HLED_voidLedOff(u8 copy_u8portTd , u8 copy_u8pinId);
void HLED_voidLedToggle(u8 copy_u8portTd , u8 copy_u8pinId);

/*collection of LEDs*/
void HLED_voidLedsOfPortOn(u8 copy_u8portTd);
void HLED_voidLedsOfPortOff(u8 copy_u8portTd);
void HLED_voidLedsOfportToggle(u8 copy_u8portTd);



#endif /* LED_INTERFACE_H_ */