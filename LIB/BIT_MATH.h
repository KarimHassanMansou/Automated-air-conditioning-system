/*
 * BIT_MATH.h
 *
 * Created: 9/6/2021 3:10:01 AM
 *  Author: karim hassan
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_


#define SET_BIT(VAR , BIT)   VAR = VAR | (1<<BIT)
#define CLR_BIT(VAR , BIT)   VAR &=~ (1<<BIT)
#define TOG_BIT(VAR , BIT)   VAR ^=  (1<<BIT)
#define GET_BIT(VAR , BIT)   ((VAR>>BIT) & 1)
#define TOG_REG(VAR)         VAR^=0xFF



#endif /* BIT_MATH_H_ */