#ifndef led_included
#define  led_included

#define RED_LED BIT0                  // P1.0
#define GREEN_LED BIT6                // P1.6
#define LEDS (BIT0 | BIT6)

void led_init();		/* initialize LEDs */
void led_update();		/* update leds */

extern unsigned char leds_changed, green_led_state, red_led_state; // Checks state of led's

#endif
