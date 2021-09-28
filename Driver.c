/* 
 * File:   Driver.c
 * Author: hp
 *
 * Created on September 28, 2021, 11:57 AM
 */

#include <avr/io.h>
#include "config.h"

/*
 * 
 */
int main(int argc, char** argv) {
    
    
    int isPressed(int portNum, int pinNum) {
    switch (portNum) {
        case _PA:
            return ((PINA & (1 << pinNum)) ? 1 : 0);
            break;
        case _PB:
            return ((PINB & (1 << pinNum)) ? 1 : 0);
            break;
        case _PC:
            return ((PINC & (1 << pinNum)) ? 1 : 0);
            break;
        case _PD:
            return ((PIND & (1 << pinNum)) ? 1 : 0);
            break;
        default: return 0;
            

    }
}

int isPress_D(int pinNum) {
    if (PIND & (1 << pinNum)) {
        return 1;
    } else {
        return 0;
    }
}

int isPress_B(int pinNum) {
    if (PINB & (1 << pinNum)) {
        return 1;
    } else {
        return 0;
    }
}

void init_Buzzer() {
    DDRA |= (1 << Buzzer);

}

void set_Buzzer(int state) {
    if (state) {
        PORTA |= (1 << Buzzer);
    } else {
        PORTA &= ~(1 << Buzzer);
    }
}

void init_Relay() {
    // Set pin connected to 
    // Relay as OUTPUT pin
    DDRA |= (1 << Relay); // Pin output

}

void set_Relay(int state) {
    if (state) {
        PORTA |= (1 << Relay); // Relay ON
    } else {
        PORTA &= ~(1 << Relay);

    }
}

void init_Leds() {

    /*
        Led0 >>   PC2
        Led1 >>   PC7
        Led2 >>   PD3
     */
    DDRC |= (1 << Led0) | (1 << Led1);
    DDRD |= (1 << Led2);


}

void set_Led(int LedNumber, int state) {

    if (state) {

        switch (LedNumber) {
            case Led0:
                PORTC |= (1 << Led0);
                break;
            case Led1:
                PORTC |= (1 << Led1);
                break;
            case Led2:
                PORTD |= (1 << Led2);
                break;
        }

    } else {
        switch (LedNumber) {
            case Led0:
                PORTC &= ~(1 << Led0);
                break;
            case Led1:
                PORTC &= ~(1 << Led1);
                break;
            case Led2:
                PORTD &= ~(1 << Led2);
                break;
        }
    }


}

void init_Buttons() {
    //    #define Btn0   0 // PB0
    DDRB &= ~(1 << Btn0);
    //    #define Btn1   6 // PD6
    DDRD &= ~(1 << Btn1);
    //    #define Btn2   2 // PD2
    DDRD &= ~(1 << Btn2);
}

    return (EXIT_SUCCESS);
}

