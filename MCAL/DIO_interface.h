/*
 * DIO_interface.h
 *
 * Created: 9/6/2021 2:57:04 AM
 *  Author: karim hassan
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "STDTYPES.h"



/*USER INTERFACE PORTS*/
#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3

/*USER INTERFACE PINS*/
#define PINA 0
#define PINB 1
#define PINC 2
#define PIND 3

/*USER INTERFACE PIN NUMBERS*/
#define PIN0  0
#define PIN1  1
#define PIN2  2
#define PIN3  3
#define PIN4  4
#define PIN5  5
#define PIN6  6
#define PIN7  7

/*USER INTERFACE DIRECTION*/
#define OUTPUT 1
#define INPUT  0

/*USER INTERFACE VALUE*/
#define HIGH 1
#define LOW  0

/*BIT MATH*/
#define SET_BIT(VAR , BIT)   VAR = VAR | (1<<BIT)
#define CLR_BIT(VAR , BIT)   VAR &=~ (1<<BIT)
#define TOG_BIT(VAR , BIT)   VAR ^=  (1<<BIT)
#define GET_BIT(VAR , BIT)   ((VAR>>BIT) & 1)
#define TOG_REG(VAR)         VAR^=0xFF




///////////////////////////////////////////////////////////////////

/**PORT FUNCTIONS**/
void MDIO_voidSetPortDirection(u8 copy_u8portTd , u8 copy_u8portDirection);
void MDIO_voidSetPortValue(u8 copy_u8portTd , u8 copy_u8portValue);
void MDIO_voidTogglePortValue(u8 copy_u8portTd);

/**PIN FUNCTIONS**/
void MDIO_voidSetPinDirection(u8 copy_u8portTd , u8 copy_u8pinId , u8 copy_u8pinDirection);
void MDIO_voidSetPinValue(u8 copy_u8portTd , u8 copy_u8pinId , u8 copy_u8portValue);
void MDIO_voidTogglePinValue(u8 copy_u8portTd , u8 copy_u8pinId);
u8 MDIO_u8GetPinValue(u8 copy_u8portTd , u8 copy_u8pinId);





#endif /* DIO_INTERFACE_H_ */