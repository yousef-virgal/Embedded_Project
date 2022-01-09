#include "systick.h"
void SystickDisable(void){Clear_Bit(NVIC_ST_CTRL_R,0);
}
void SystickEnable (void){
    Set_Bit(NVIC_ST_CTRL_R,0);
}
void SystickPeriod(uint32_t ui32Period){

    ui32Period=(ui32Period* 16000)-1;
    NVIC_ST_RELOAD_R=ui32Period;
}
bool Systick_Is_Time_out(void){
    if (Get_Bit(NVIC_ST_CTRL_R,16)==0)
    return 0;
    else{
        return 1;
    }
}
void SystickSetClockSource (int source){
  if(source == internal){
    Set_Bit(NVIC_ST_CTRL_R,2);}
    else{
      Clear_Bit(NVIC_ST_CTRL_R,2);}
}