/**
 * lab4_template.c
 *
 * Template file for CprE 288 lab 4
 *
 * @author Zhao Zhang, Chad Nelson, Zachary Glanz
 * @date 08/14/2016
 */

#include "button.h"
#include "Timer.h"
#include "lcd.h"
#include "cyBot_uart.h"  // Functions for communicating between CyBot and Putty (via UART)
                         // PuTTy: Baud=115200, 8 data bits, No Flow Control, No Parity, COM1
void sendBackString(const char *recieved);
#define REPLACEME 0



int main(void) {
    button_init();
    timer_init(); // Must be called before lcd_init(), which uses timer functions
    lcd_init();

    lcd_putc('8');
    cyBot_uart_init();
                // Don't forget to initialize the cyBot UART before trying to use it

    // YOUR CODE HERE
    char message[30];
    char oldMessage[30] = "";

    uint8_t previousState = 0;

    while(1)
    {
        // YOUR CODE HERE
        uint8_t bruhman = button_getButton();

        if (bruhman != previousState) {
            if (bruhman != 0) {
                switch(bruhman) {
                case '\x01':
                    sprintf(message, "Hi TA!\n");
                    break;
                case '\x02':
                    sprintf(message, "Whats goodie gang\n");
                    break;
                case '\x03':
                    sprintf(message, "I am not ready for lab 5\n");
                    break;
                case '\x04':
                    sprintf(message, "Low Taper Fade\n");
                    break;
                default:
                    sprintf(message, "No button");
                    break;
                }

                sendBackString(message);
            }

            previousState = bruhman;
        }
    }
}

void sendBackString(const char *recieved)
{
    int i;
    for(i = 0; i < strlen(recieved); i++)
    {


        cyBot_sendByte(*(recieved + i));

    }

}
