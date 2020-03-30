#include <msp430.h>
#include "led.h"
#include "switches.h"

void led_init()
{
  P1DIR |= LEDS;		// bits attached to leds are output
  switch_state_changed = 1;
  led_update();
}

void led_update(){
  if (switch_state_changed) {
    char ledFlags = 0;         // if button is pressed, turn Green LED, else turn Red
    
    ledFlags |= switch_state_down ? GREEN_LED : RED_LED; /* On green led */
 
    P1OUT &= (0xff - LEDS) | ledFlags; // clear bits for off leds
    P1OUT |= ledFlags; // set bits for on leds
  }
  switch_state_changed = 0;
 }