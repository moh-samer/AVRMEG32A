/* 
 * File:   Driver.h
 * Author: hp
 *
 * Created on September 28, 2021, 11:57 AM
 */

#ifndef DRIVER_H
#define	DRIVER_H

#ifdef	__cplusplus
extern "C" {
#endif

void init_Relay();
void set_Relay(int state);
void init_Buzzer();
void set_Buzzer(int state);

void init_Leds();
void set_Led(int LedNumber, int state);

void init_Buttons();

int isPress_B(int pinNum);
int isPressed(int portNum, int pinNum);
int isPress_D(int pinNum);


#ifdef	__cplusplus
}
#endif

#endif	/* DRIVER_H */

