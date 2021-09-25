/*
 * File:   main.c
 * Author: hossa
 *
 * Created on September 24, 2021, 11:18 AM
 */

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

void init_Relay();
void set_Relay(int state);
void init_Buzzer();
void set_Buzzer(int state);

void init_Leds();
void set_Led(int LedNumber, int state);

void init_Buttons();

int isPress_B(int pinNum);
int isPressed(int portNum, int pinNum);

int main(void) {
    /* Replace with your application code */
    // Static
    init_Leds();
    init_Buttons();
    while (1) {

        if (isPressed(_PB, Btn0)) {
            // Pressed
            set_Led(Led0, ON);
            set_Led(Led1, ON);
            set_Led(Led2, ON);
        } else {
            // Release
            set_Led(Led0, OFF);
            set_Led(Led1, OFF);
            set_Led(Led2, OFF);
        }



    }
    return 0;
}

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