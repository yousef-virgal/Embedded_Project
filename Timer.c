# include "Timer.h"
//todo add priorities
void timer_init(int8 timernumber, int32 prescaleval,int8 interruptval)
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

void timer_set(int8 timernumber,int32 time)
// time is the hexadecimal value 
{
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

void stop_timer(int8 timernumber)
{
    switch(timernumber)
    {
    case TIMER0:
        Clear_Bit(TIMER0_CTL_R,0);
        break;
    case TIMER1:
        Clear_Bit(TIMER1_CTL_R,0);
        break;

    case TIMER2:
        Clear_Bit(TIMER2_CTL_R,0);
        break;
    case TIMER3:
        Clear_Bit(TIMER3_CTL_R,0);
        break;
    case TIMER4:
        Clear_Bit(TIMER4_CTL_R,0);
        break;
    case TIMER5:
        Clear_Bit(TIMER5_CTL_R,0);
        break;
    }
}


void resume_timer(int8 timernumber)
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