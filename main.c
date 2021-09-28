/*
 * File:   main.c
 * Author: hossa
 *
 * Created on September 24, 2021, 11:18 AM
 */
# include <avr/io.h>
#include "config.h"
# include <util/delay.h>



int main(void) {
    /* Replace with your application code */
    // Static
    init_Leds();
    init_Buttons();
    init_Relay();
    init_Buzzer();
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
        //bazzer

        if (isPressed(_PD, Btn2)) {
            // Pressed
            set_Buzzer(ON);

        } else {
            // Release
            set_Buzzer(OFF);
        }




        // relay
        if (isPressed(_PD, Btn1)) {
            // Pressed
            set_Relay(ON);

        } else {
            // Release
            set_Relay(OFF);
        }


    }
    return 0;
}

