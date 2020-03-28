#include <msp430.h>
#include "switches.h"
#include "buzzer.h"

/* Switch on P1 (S2) */
void
__interrupt_vec(WDT_VECTOR) WDT() {
  static char count = 0;
  if(++ count == tempo) {
    int repeat = 1;
    while(repeat <= 5) {
      int cnt = 0;
      buzzer_set_period(0);
      while(cnt < 30000) {
	cnt++;
      }
      repeat++;
    }
   
    switch_interrupt_handler();	/* single handler for all switches */
    count = 0;
  }
}

