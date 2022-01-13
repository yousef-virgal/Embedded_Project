#include "DIO.h"
#include "MyTimer.h"
#include <stdint.h>
#include "systick.h"
#define YES 1
#define NO 0
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
};
static enum traffic stateoftraffic = red;
static enum trafficstate direction = northsouth;
// variable controlling entering pedestrian button interrupts multiple times
static int8 firedbefore = NO;
int main()
{

  __asm(" CPSIE I");
  // initializing ports
  DIO_Init_Port(PORTB); // north south traffic
  DIO_Init_Port(PORTC); // east west traffic
  DIO_Init_Port(PORTD); // Pedestrians traffic
  // East-West Traffic
  DIO_Init_Pin(PORTC, 4, OUT_DIR); // Red
  DIO_Init_Pin(PORTC, 5, OUT_DIR); // Green
  DIO_Init_Pin(PORTC, 6, OUT_DIR); // Yellow
  // North-South Traffic
  DIO_Init_Pin(PORTB, 3, OUT_DIR); // Red
  DIO_Init_Pin(PORTB, 6, OUT_DIR); // Green
  DIO_Init_Pin(PORTB, 7, OUT_DIR); // Yellow
  // enabling port b interrupts
  Set_Bit(NVIC_EN0_R, 1);
  // User Push buttons
  DIO_Init_Pin(PORTB, 0, IN_DIR); // pedestrian 1
  Set_Bit(GPIO_PORTB_IEV_R, 0);   // assigning interrupt event for port b pin 0
  Set_Bit(GPIO_PORTB_IM_R, 0);    // interrupt masking for port b pin 0
  DIO_Init_Pin(PORTB, 1, IN_DIR); // pedestrian 2
  Set_Bit(GPIO_PORTB_IEV_R, 1);   // assigning interrupt event for port b pin 1
  Set_Bit(GPIO_PORTB_IM_R, 1);    // interrupt masking for port b pin 1
  // pedestrians lights 1
  DIO_Init_Pin(PORTD, 2, OUT_DIR);
  DIO_Init_Pin(PORTD, 3, OUT_DIR);
  // pedestrians lights 2
  DIO_Init_Pin(PORTB, 5, OUT_DIR);
  DIO_Init_Pin(PORTB, 4, OUT_DIR);
  // initializing closed pedestrian cross1
  DIO_WritePin(PORTD, 2, 1);
  DIO_WritePin(PORTD, 3, 0);
  // initializing closed pedestrian cross1
  DIO_WritePin(PORTB, 5, 1);
  DIO_WritePin(PORTB, 4, 1);
  // initial traffic lights before FSM starts
  DIO_WritePin(PORTC, 4, 1);
  DIO_WritePin(PORTB, 3, 1);
  // initializing systick
  SystickDisable();
  SystickSetClockSource(internal);
  SysticDisableIntrupt();
  SystickPeriod(10);

  Timer_Init(TIMER0, INTERRUPT);
  Timer_Set(TIMER0, 1000);
  Set_Bit(NVIC_PRI0_R, 14); // prioritizing push buttons on port b
  Set_Bit(NVIC_PRI5_R, 13); // prioritizing Timer 1 more than push buttons
  Set_Bit(NVIC_PRI4_R, 31); // prioritizing Timer 1 more than push buttons

  while (1)
  {
    __asm(" wfi \n");
  }
}

void Traffic_Timer_IntHandler(void)
{
  // clear interrupt
  // stop timer
  Timer_Stop(TIMER0);
  switch (stateoftraffic)
  {
  case red:
    if (direction == northsouth)
    {
      direction = eastwest;
      DIO_WritePin(PORTC, 4, 0); // colse Eastwest red
      DIO_WritePin(PORTC, 5, 1); // open Eastwest green
      Timer_Set(TIMER0, 5000);   // setting green interval for 5 seconds
    }
    else
    {
      direction = northsouth;
      DIO_WritePin(PORTB, 3, 0); // colse Northsouth red
      DIO_WritePin(PORTB, 6, 1); // open Northsouth green
      Timer_Set(TIMER0, 5000);   // setting green interval for 5 seconds
    }
    stateoftraffic = green;
    break;
  case green:
    if (direction == northsouth)
    {

      DIO_WritePin(PORTB, 7, 1); // open Northsouth yellow
      DIO_WritePin(PORTB, 6, 0); // close Northsouth Green
      Timer_Set(TIMER0, 2000);   // setting Yellow interval for 1 second
    }
    else
    {

      DIO_WritePin(PORTC, 6, 1); // open Eastwest yellow
      DIO_WritePin(PORTC, 5, 0); // close Eastwest green
      Timer_Set(TIMER0, 2000);   // setting yellow interval for 1 second
      Timer_Resume(TIMER0);      // Resume the timer
    }
    stateoftraffic = yellow;
    break;
  case yellow:
    if (direction == northsouth)
    {

      DIO_WritePin(PORTB, 3, 1); // open Northsouth red
      DIO_WritePin(PORTB, 7, 0); // close Northsouth yellow
      Timer_Set(TIMER0, 1000);   // setting red interval for 1 second
    }
    else
    {

      DIO_WritePin(PORTC, 4, 1); // open Eastwest red
      DIO_WritePin(PORTC, 6, 0); // close Eastwest yellow
      Timer_Set(TIMER0, 1000);   // setting red interval for 1 second
    }
    stateoftraffic = red;
    break;

  default:
    break;
  }

  // start timer
}
void Pedestrian_Button_Handler(void)
{
  // Enable systick
  SystickEnable();
  //wait for systick to timeout
  while (Systick_Is_Time_out() == 0)
  {
  }
  SystickDisable();
  //check if there is any button still pushed
  if (DIO_ReadPin(PORTB, 0) == 0 || DIO_ReadPin(PORTB, 1) == 0)
  {
    if (firedbefore == YES)
    {
      Set_Bit(GPIO_PORTB_ICR_R, 0);
      Set_Bit(GPIO_PORTB_ICR_R, 1);
      return;
    }

    Timer_Stop(TIMER0);
    Timer_Init(TIMER1, INTERRUPT);
    // timers traffic
    // change leds
    DIO_WritePin(PORTC, 4, 1);
    DIO_WritePin(PORTC, 5, 0);
    DIO_WritePin(PORTC, 6, 0);
    DIO_WritePin(PORTB, 3, 1);
    DIO_WritePin(PORTB, 6, 0);
    DIO_WritePin(PORTB, 7, 0);
    // start timer
    Timer_Set(TIMER1, 2000);
    DIO_WritePin(PORTD, 2, 0);
    DIO_WritePin(PORTD, 3, 1);
    firedbefore = YES;
    // clear interrupt flags
  }
  SystickReset();
}
void Pedestrian_Timer_IntHandler(void)
{
  //  DIO_WritePin(PORTD,2,0);
  //  DIO_WritePin(PORTD,3,1);
  Timer_Stop(TIMER1);
  switch (stateoftraffic)
  {
  case red:
    // both leds are already red from previous state
    Timer_Resume(TIMER0);
    break;
  case green:
    if (direction == eastwest)
    {
      DIO_WritePin(PORTC, 4, 0); // close northsouth red
      DIO_WritePin(PORTC, 5, 1); // open Northsouth green
      Timer_Resume(TIMER0);      // Resume the timer from previous reload value
    }
    else
    {

      DIO_WritePin(PORTB, 3, 0); // close eastwest red
      DIO_WritePin(PORTB, 6, 1); // open eastwest green
      Timer_Resume(TIMER0);      // Resume the timer from previous reload value
    }
    break;
  case yellow:
    if (direction == eastwest)
    {
      DIO_WritePin(PORTC, 4, 0); // close northsouth red
      DIO_WritePin(PORTC, 6, 1); // open northsouth yellow
      Timer_Resume(TIMER0);      // Resume the timer from previous reload value
    }
    else
    {

      DIO_WritePin(PORTB, 3, 0); // close eastwest red
      DIO_WritePin(PORTB, 7, 1); // open eastwest yellow
      Timer_Resume(TIMER0);      // Resume the timer from previous reload value
    }
    break;

  default:
    break;
  }
  // open pedestrian reds again and close pedestrian greens
  DIO_WritePin(PORTD, 2, 1);
  DIO_WritePin(PORTD, 3, 0);

  //
  // enabling interrupts for pedestrians again
  firedbefore = NO;
  // clearing interrupt flags
  Set_Bit(GPIO_PORTB_ICR_R, 0);
  Set_Bit(GPIO_PORTB_ICR_R, 1);
}
