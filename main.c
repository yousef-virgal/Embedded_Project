#include "DIO.h"
#include "stdio.h"
#include "Timer.h"
//#include "systick.h"
//trafic1,2 green w yellow w red 

enum traffic {red, yellow ,green};

enum direction {northsouth,eastwest}//kfaya habd!!!!!!!!!  


int main()
{
__asm(" CPSIE I");
static enum currenttrafficstate  stateoftraffic = traffic1;
static enum direction trafficstate = northsouth;

while(1){
  __asm(" wfi \n");
}

}


void Pedestrian_Timer_IntHandler(void)
{
 if (trafficstate == northsouth){
   if stateoftraffic  == green:
    led== green
   if stateoftraffic  == yellow:
   led2 == red   

 }
  
 else east wset
}

void Traffic_Timer_IntHandler(void){
//clear interrupt
//stop timer 
switch(currentstate):
case grren:
  led yellow
case:
  led
case: 
case green_red:
set timer 
colors 

//start timer
}
void Pedestrian_Button_Handler(void)
{
  // timers traffic
  // change leds
  // start timer
}
