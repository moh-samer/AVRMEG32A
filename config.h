/* 
 * File:   config.h
 * Author: hp
 *
 * Created on September 28, 2021, 11:51 AM
 */
# include "Driver.h"
# include "Uart.h"

#ifndef CONFIG_H
#define	CONFIG_H

#ifdef	__cplusplus
extern "C" {
#endif

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>


#define _PA   0
#define _PB   1
#define _PC   2
#define _PD   3

#define Relay  2 // PA2
#define Buzzer 3 // PA2

#define Led0   2 // PC2
#define Led1   7 // PC7
#define Led2   3 // PD3

#define Btn0   0 // PB0
#define Btn1   6 // PD6
#define Btn2   2 // PD2

#define ON  1
#define OFF 0



#ifdef	__cplusplus
}
#endif

#endif	/* CONFIG_H */
