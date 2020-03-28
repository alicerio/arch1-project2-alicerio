#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "buzzer.h"
#include "libTimer.h"

char switch_state_down, switch_state_changed, tempo; /* effectively boolean */

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
  else if (!(p2val & SW4)) {
    tempo = 50;
    MarioTheme();
    switch_state_down = 1;
  }
  else if (!(p2val & SW3)) {
    tempo = 22;
    starTheme();
    switch_state_down = 1;
  }
  else if (!(p2val & SW2)) {
    tempo = 97;
    ironManTheme();
    switch_state_down = 1;
  }
  else if (!(p2val & SW1)) {
    tempo = 120;
    starWars();
    switch_state_down = 1;
  }
  switch_state_changed = 1;
  led_update();
}

    















  
    













    
  

