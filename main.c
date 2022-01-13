#include "DIO.h"
#include "MyTimer.h"
#include <stdint.h>

enum traffic
{
  red,
  yellow,
  green
};
enum trafficstate
{
  northsouth,
  eastwest
}; //kfaya habd!!!!!!!!!
static enum traffic stateoftraffic = red;
static enum  trafficstate direction  = northsouth;
int main()
{

  __asm(" CPSIE I");
//East-West Traffic
DIO_Init(PORTC, 4, OUT_DIR); //Red
DIO_Init(PORTC, 5, OUT_DIR); //Green
DIO_Init(PORTC, 6, OUT_DIR); //Yellow
//North-South Traffic
DIO_Init(PORTF, 1, OUT_DIR); //Red
DIO_Init(PORTF, 3, OUT_DIR); //Green
DIO_Init(PORTF, 2, OUT_DIR); //Yellow
//enabling port b interrupts
  Set_Bit(NVIC_EN0_R,1);
//User Push buttons
DIO_Init(PORTB, 0, IN_DIR); //pedestrian 1
Set_Bit(GPIO_PORTB_IEV_R,0);//assigning interrupt event for port b pin 0
Set_Bit(GPIO_PORTB_IM_R,0);//interrupt masking for port b pin 0
DIO_Init(PORTB, 1, IN_DIR); //pedestrian 2
Set_Bit(GPIO_PORTB_IEV_R,1);//assigning interrupt event for port b pin 0
Set_Bit(GPIO_PORTB_IM_R,1);//interrupt masking for port b pin 1
DIO_Init(PORTE,4,OUT_DIR);
DIO_WritePin(PORTE,4,1);
//clearing default pull up resistors

//defining pull down resistors

  Timer_Init(TIMER0, INTERRUPT);
  Timer_Set(TIMER0, 1000);
  while (1)
  {
    __asm(" wfi \n");

  }
}



void Traffic_Timer_IntHandler(void)
{
  //clear interrupt
  //stop timer
  Timer_Stop(TIMER0);
  switch (stateoftraffic)
  {
  case red:
    if (direction == northsouth)
    {
      direction = eastwest;
      DIO_WritePin(PORTC, 4, 0); //colse Eastwest red
      DIO_WritePin(PORTC, 5, 1); //open Eastwest green
      Timer_Set(TIMER0, 5000);   //setting green interval for 5 seconds
      Timer_Resume(TIMER0);      //Resume the timer
    }
    else
    {
      direction = northsouth;
      DIO_WritePin(PORTD, 1, 0); //colse Northsouth red
      DIO_WritePin(PORTD, 2, 1); //open Northsouth green
      Timer_Set(TIMER0, 5000);   //setting green interval for 5 seconds
      Timer_Resume(TIMER0);      //Resume the timer
    }
    stateoftraffic=green;
    break;
  case green:
    if (direction == northsouth)
    {

      DIO_WritePin(PORTD, 3, 1); //open Northsouth yellow
      DIO_WritePin(PORTD, 2, 0); //close Northsouth Green
      Timer_Set(TIMER0, 2000);   //setting Yellow interval for 1 second
      Timer_Resume(TIMER0);      //Resume the timer
    }
    else
    {

      DIO_WritePin(PORTC, 6, 1); //open Eastwest yellow
      DIO_WritePin(PORTC, 5, 0); //close Eastwest green
      Timer_Set(TIMER0, 2000);   //setting yellow interval for 1 second
      Timer_Resume(TIMER0);      //Resume the timer
    }
    stateoftraffic=yellow;
    break;
    case yellow:
    if (direction == northsouth)
    {

      DIO_WritePin(PORTD, 1, 1); //open Northsouth red
      DIO_WritePin(PORTD, 3, 0); //close Northsouth yellow
      Timer_Set(TIMER0, 1000);   //setting red interval for 1 second
      Timer_Resume(TIMER0);      //Resume the timer
    }
    else
    {

      DIO_WritePin(PORTC, 4, 1); //open Eastwest red
      DIO_WritePin(PORTC, 6, 0); //close Eastwest yellow
      Timer_Set(TIMER0, 1000);   //setting red interval for 1 second
      Timer_Resume(TIMER0);      //Resume the timer
    }
    stateoftraffic=red;
    break;


  default:
    break;
  }

  //start timer
}
void Pedestrian_Button_Handler(void)
{
  Timer_Stop(TIMER0);
  Timer_Init(TIMER1,INTERRUPT);
  // timers traffic
  // change leds
  DIO_WritePin(PORTC,4,1);
  DIO_WritePin(PORTC,5,0);
  DIO_WritePin(PORTC,6,0);
  DIO_WritePin(PORTF,1,1);
  DIO_WritePin(PORTF,3,1);
  DIO_WritePin(PORTF,2,1);
  // start timer
  Timer_Set(TIMER1,2000);
  DIO_WritePin(PORTE,4,0);
  //clear interrupt flags
  Set_Bit(GPIO_PORTB_ICR_R,0);
  Set_Bit(GPIO_PORTB_ICR_R,1);
 
}
void Pedestrian_Timer_IntHandler(void)
{
  DIO_WritePin(PORTE,4,0);
  Timer_Stop(TIMER1);
  switch (stateoftraffic)
  {
  case red:
    //both leds are already red from previous state
    Timer_Resume(TIMER0);
    break;
  case green:
    if (direction == northsouth)
    {
      DIO_WritePin(PORTC,4,0);//close northsouth red
      DIO_WritePin(PORTC, 5, 1); //open Northsouth green
      Timer_Resume(TIMER0);      //Resume the timer from previous reload value
    }
    else
    {

      DIO_WritePin(PORTF,1,0);//close eastwest green
      DIO_WritePin(PORTF, 3, 1); //open eastwest green
      Timer_Resume(TIMER0);      //Resume the timer from previous reload value
    }
    stateoftraffic=yellow;
    break;
    case yellow:
    if (direction == northsouth)
    {
      DIO_WritePin(PORTC,4,0);//close northsouth green
      DIO_WritePin(PORTC, 6, 1); //open Northsouth yellow
      Timer_Resume(TIMER0);      //Resume the timer from previous reload value
    }
    else
    {

      DIO_WritePin(PORTF,1,0);//close eastwest red
      DIO_WritePin(PORTF, 2, 1); //open eastwest yellow
      Timer_Resume(TIMER0);      //Resume the timer from previous reload value
    }
    stateoftraffic=red;
    break;


  default:
    break;
  }

}

