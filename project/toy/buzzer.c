#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

static int ironManSong = 0;
static int firstSong = 0;
static int secondSong = 0;
static int starSong = 0;

void buzzer_init()
{
    /* 
       Direct timer A output "TA0.1" to P2.6.  
        According to table 21 from data sheet:
          P2SEL2.6, P2SEL2.7, anmd P2SEL.7 must be zero
          P2SEL.6 must be 1
        Also: P2.6 direction must be output
    */
    timerAUpmode();		/* used to drive speaker */
    P2SEL2 &= ~(BIT6 | BIT7);
    P2SEL &= ~BIT7; 
    P2SEL |= BIT6;
    P2DIR = BIT6; /* enable output to speaker (P2.6) */
}
void ironManTheme(){
  switch(ironManSong) {
  case 0: buzzer_set_period(750); ironManSong++; break;
  case 1:
  case 2:
  case 11:
  case 12: buzzer_set_period(630); ironManSong++; break;
  case 3:
  case 4:
  case 13:
  case 14: buzzer_set_period(560);
    if(ironManSong == 14) {
      ironManSong = 0;
    }
    else {
      ironManSong++;
    }
    break;
  case 5:
  case 7:
  case 9: buzzer_set_period(950); ironManSong++; break;
  case 6:
  case 8:
  case 10: buzzer_set_period(500); ironManSong++; break;
  }
}

void FirstTheme() {
  switch(firstSong) {
  case 0:
  case 1:
  case 2:
  case 4: buzzer_set_period(400); firstSong++; break;
  case 3: buzzer_set_period(670); firstSong++; break;
  case 5: buzzer_set_period(934); firstSong++; break;
  case 6: buzzer_set_period(1000); firstSong++; break;
  }
}

void SecondTheme() {
  switch(secondSong) {
  case 0: buzzer_set_period(950); secondSong++; break;
  case 1:
  case 6:
  case 11: buzzer_set_period(740); secondSong++; break;
  case 2:
  case 7:
  case 12:
  case 14: buzzer_set_period(630); secondSong++; break;
  case 3:
  case 13: buzzer_set_period(870); secondSong++; break;
  case 4:
  case 9:
  case 15: buzzer_set_period(590);
    if(secondSong == 15) {
      secondSong = 0;
    }
    else {
      secondSong++;
    }
    break;
  case 5:
  case 10: buzzer_set_period(700); secondSong++; break;
  }
}

void starTheme() {
  switch(starSong) {
  case 0:
  case 1:
  case 2:
  case 3:
  case 4:
  case 6:
  case 8: buzzer_set_period(950); starSong++; break;
  case 5:
  case 7: buzzer_set_period(1130); starSong++; break;
  case 9:
  case 10:
  case 11:
  case 12:
  case 13:
  case 15:
  case 17: buzzer_set_period(1000);
    if(starSong == 17) {
      starSong = 0;
    }
    else {
      starSong++;
    }
    break;
  case 14:
  case 16: buzzer_set_period(1270);
  }
}

void buzzer_set_period(short cycles) /* buzzer clock = 2MHz.  (period of 1k results in 2kHz tone) */
{
  CCR0 = cycles; 
  CCR1 = cycles >> 1;		/* one half cycle */
}


    
    
  

