# include "MyTimer.h"
#include <stdint.h>


void Timer_Init(int8 timernumber,int8 interruptval)
// Input: timer number : {Timer0,Timer1,...,Timer5}
// Input: interuptval: {INTERRUPT,NOINTERRUPT}
// Returns void  
// configures a certain timer to be 32 bit wide periodc down counting timer, with timeout intrupts enabled or disabled on this timer 
{
    Set_Bit(SYSCTL_RCGCTIMER_R,timernumber);
    
    switch(timernumber)
    {

    case TIMER0:
        Clear_Bit(TIMER0_CTL_R,0);
        Set_Register(TIMER0_CFG_R,0);
        Set_Register(TIMER0_TAMR_R,0x02U);// down counting
        Set_Register(TIMER0_ICR_R,0x01U);
        if(interruptval==INTERRUPT){
        Set_Register(TIMER0_IMR_R,0x01U);
        Set_Bit(NVIC_EN0_R,19);
        }
        else{
        Set_Register(TIMER0_IMR_R,0x0U);
        }
        break;
    case TIMER1:
        Clear_Bit(TIMER1_CTL_R,0);
        Set_Register(TIMER1_CFG_R,0);
        Set_Register(TIMER1_TAMR_R,0x02U);// down counting
        Set_Register(TIMER1_ICR_R,0x01U);
        if(interruptval==INTERRUPT){
        Set_Register(TIMER1_IMR_R,0x01U);
        Set_Bit(NVIC_EN0_R,21);
        }
        else{
        Set_Register(TIMER1_IMR_R,0x0U);
        }
        break;

    case TIMER2:
        Clear_Bit(TIMER2_CTL_R,0);
        Set_Register(TIMER2_CFG_R,0);
        Set_Register(TIMER2_TAMR_R,0x02U);// down counting
        Set_Register(TIMER2_ICR_R,0x01U);
        if(interruptval==INTERRUPT){
        Set_Register(TIMER2_IMR_R,0x01U);
        Set_Bit(NVIC_EN0_R,23);
        }
        else{
        Set_Register(TIMER2_IMR_R,0x0U);
        }
        break;
    case TIMER3:
        Clear_Bit(TIMER3_CTL_R,0);
        Set_Register(TIMER3_CFG_R,0);
        Set_Register(TIMER3_ICR_R,0x01U);
        if(interruptval==INTERRUPT){
        Set_Register(TIMER3_IMR_R,0x01U);
        Set_Bit(NVIC_EN1_R,3);
        }
        else{
        Set_Register(TIMER3_IMR_R,0x0U);
        }
        break;
    case TIMER4:
        Clear_Bit(TIMER4_CTL_R,0);
        Set_Register(TIMER4_CFG_R,0);
        Set_Register(TIMER4_ICR_R,0x01U);
        if(interruptval==INTERRUPT){
        Set_Register(TIMER4_IMR_R,0x01U);
        Set_Bit(NVIC_EN2_R,6);
        }
        else{
        Set_Register(TIMER0_ICR_R,0x0U);
        Set_Register(TIMER0_IMR_R,0x0U);
        }
        break;
    case TIMER5:
        Clear_Bit(TIMER5_CTL_R,0);
        Set_Register(TIMER5_CFG_R,0);
        Set_Register(TIMER2_ICR_R,0x01U);
        if(interruptval==INTERRUPT){
        Set_Register(TIMER2_IMR_R,0x01U);
        Set_Bit(NVIC_EN2_R,28);
        }
        else{
        Set_Register(TIMER0_ICR_R,0x0U);
        Set_Register(TIMER0_IMR_R,0x0U);
        }
        break;
        
    }
    
}

void Timer_Set(int8 timernumber,uint32 time)
// Input: timer number : {Timer0,Timer1,...,Timer5}
// Input: time unsinged intger 32 bits
// Returns void  
// the time in miliseconds is taken as pararmeter and  is used to configure the timers reload value and enable the timer to start counting
{   
    //setting the time value in ticks to be added in the Interval load register

    time=(time* 16000)-1;

    switch(timernumber)
    {
    case TIMER0:
        Clear_Bit(TIMER0_CTL_R,0);
        Set_Register(TIMER0_TAILR_R,time);
        Set_Bit(TIMER0_CTL_R,0);
        break;
    case TIMER1:
        Clear_Bit(TIMER1_CTL_R,0);
        Set_Register(TIMER1_TAILR_R,time);
        Set_Bit(TIMER1_CTL_R,0);
        break;

    case TIMER2:
        Clear_Bit(TIMER2_CTL_R,0);
        Set_Register(TIMER2_TAILR_R,time);
        Set_Bit(TIMER2_CTL_R,0);
        break;
    case TIMER3:
        Clear_Bit(TIMER3_CTL_R,0);
        Set_Register(TIMER3_TAILR_R,time);
        Set_Bit(TIMER3_CTL_R,0);
        break;
    case TIMER4:
        Clear_Bit(TIMER4_CTL_R,0);
        Set_Register(TIMER4_TAILR_R,time);
        Set_Bit(TIMER4_CTL_R,0);
        break;
    case TIMER5:
        Clear_Bit(TIMER5_CTL_R,0);
        Set_Register(TIMER5_TAILR_R,time);
        Set_Bit(TIMER5_CTL_R,0);
        break;
    
    }

}

void Timer_Stop(int8 timernumber)
// Input: timer number : {Timer0,Timer1,...,Timer5}
// Returns void  
// stops the timer from counting and clears the timeout interrupt flag

{
    switch(timernumber)
    {
    case TIMER0:
        Clear_Bit(TIMER0_CTL_R,0);
        Set_Register(TIMER0_ICR_R,0x01U);
        break;
    case TIMER1:
        Clear_Bit(TIMER1_CTL_R,0);
        Set_Register(TIMER1_ICR_R,0x01U);
        break;

    case TIMER2:
        Clear_Bit(TIMER2_CTL_R,0);
        Set_Register(TIMER2_ICR_R,0x01U);
        break;
    case TIMER3:
        Clear_Bit(TIMER3_CTL_R,0);
        Set_Register(TIMER3_ICR_R,0x01U);
        break;
    case TIMER4:
        Clear_Bit(TIMER4_CTL_R,0);
        Set_Register(TIMER4_ICR_R,0x01U);
        break;
    case TIMER5:
        Clear_Bit(TIMER5_CTL_R,0);
        Set_Register(TIMER5_ICR_R,0x01U);
        break;
    }
}


void Timer_Resume(int8 timernumber)
// Input: timer number : {Timer0,Timer1,...,Timer5}
// Returns void  
// sets the enbale bit int the timers control Regesiter for it to start counting again 

{
    switch(timernumber)
    {
    case TIMER0:
        Set_Bit(TIMER0_CTL_R,0);
        break;
    case TIMER1:
        Set_Bit(TIMER1_CTL_R,0);
        break;

    case TIMER2:
        Set_Bit(TIMER2_CTL_R,0);
        break;
    case TIMER3:
        Set_Bit(TIMER3_CTL_R,0);
        break;
    case TIMER4:
        Set_Bit(TIMER4_CTL_R,0);
        break;
    case TIMER5:
        Set_Bit(TIMER5_CTL_R,0);
        break;
    }
}