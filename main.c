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
//DIO_Init(PORTF, 1, OUT_DIR); //Red
//DIO_Init(PORTF, 2, OUT_DIR); //Green
//DIO_Init(PORTB, 3, OUT_DIR); //Yellow
//DIO_WritePin(PORTF,1,1);
//DIO_WritePin(PORTF,2,1);
//DIO_WritePin(PORTF,3,1);
  //enable interrupts
  __asm(" CPSIE I");
//East-West Traffic
DIO_Init(PORTC, 4, OUT_DIR); //Red
DIO_Init(PORTC, 5, OUT_DIR); //Green
DIO_Init(PORTC, 6, OUT_DIR); //Yellow
//North-South Traffic
DIO_Init(PORTD, 1, OUT_DIR); //Red
DIO_Init(PORTD, 2, OUT_DIR); //Green
DIO_Init(PORTD, 3, OUT_DIR); //Yellow
//enabling port b interrupts
  Set_Bit(NVIC_EN0_R,1);
  Set_Bit(NVIC_EN0_R,2);
//User Push buttons
DIO_Init(PORTC, 7, IN_DIR); //pedestrian 1
Set_Bit(GPIO_PORTC_IEV_R,7);
Set_Bit(GPIO_PORTC_IM_R,7);
//Clear_Bit(GPIO_PORTC_PUR_R, 7);
//Set_Bit(GPIO_PORTC_PDR_R, 7);



DIO_Init(PORTB, 1, IN_DIR); //pedestrian 2
// setting interrupt mask on both pins
Set_Bit(GPIO_PORTB_IEV_R,0);
Set_Bit(GPIO_PORTB_IEV_R,1);

Set_Bit(GPIO_PORTB_IM_R,0);
Set_Bit(GPIO_PORTB_IM_R,1);

//clearing default pull up resistors
Clear_Bit(GPIO_PORTB_PUR_R, 0);
Clear_Bit(GPIO_PORTB_PUR_R, 1);
//defining pull down resistors
Set_Bit(GPIO_PORTB_PDR_R, 0);
Set_Bit(GPIO_PORTB_PDR_R, 1);
  Timer_Init(TIMER0, INTERRUPT);
  Timer_Set(TIMER0, 1000);
  while (1)
  {
    __asm(" wfi \n");
    if(DIO_ReadPin(PORTC,7)==1)
    {
      int x=1;
      for(x=1;x<10;x++)
      {
        x++;
      }
      
    }
  }
}

void Pedestrian_Timer_IntHandler(void)
{
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
  Timer_Set(TIMER1,2000);
  // timers traffic
  // change leds
  // start timer
  Set_Bit(GPIO_PORTC_ICR_R,7)
}
