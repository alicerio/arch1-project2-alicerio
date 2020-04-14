#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "buzzer.h"
#include "libTimer.h"
#include "stateMachine.h"

char switch_state_down, tempo, switch_state_changed; /* Boolean operators */
char switch_state;

static char
switch_update_interrupt_sense()
{
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & SWITCHES);
  P2IES &= (p2val | ~SWITCHES);
  return p2val;
}

void
switch_init()                 /* setup switch */
{
  P2REN   |= SWITCHES;        /* enables resistors for switches */
  P2IE = SWITCHES;            /* enable interrupts from switches */
  P2OUT |= SWITCHES;          /* pull-ups for switches */
  P2DIR &= ~SWITCHES;         /* set switches' bits for input */
}

void
switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();
  if (p2val & SW1 && p2val & SW2 && p2val & SW3 && p2val & SW4) {
    buzzer_set_period(0);
    switch_state_down = 0;
  }
  else if (!(p2val & SW4)) {     // Realized operations if switch 4 is pressed.
    tempo = 50;
    FirstTheme();
    switch_state_down = 1;
    switch_state = 4;
  }
  else if (!(p2val & SW3)) {     // Realized operations if switch 3 is pressed.
    tempo = 22;
    starTheme();
    switch_state_down = 1;
    switch_state = 3;
  }
  else if (!(p2val & SW2)) {     // Realized operations if switch 2 is pressed.
    tempo = 97;
    ironManTheme();
    switch_state_down = 1;
    switch_state = 2;
  }
  else if (!(p2val & SW1)) {     // Realized operations if switch 1 is pressed.
    tempo = 120;
    SecondTheme();
    switch_state_down = 1;
    switch_state = 1;
  }
   led_update();
   switch_state_changed = 1;
}

    















  
    













    
  

