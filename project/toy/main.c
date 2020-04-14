#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "led.h"
#include "switches.h"

void main() {
  configureClocks();         // Configures the clock from the libTimer file
  switch_init();             // Initializes switches
  buzzer_init();             // Initializes buzzer
  led_init();                // Initializes the LED's 
  enableWDTInterrupts();     // Enables the interrupts
  or_sr(0x18);
}
