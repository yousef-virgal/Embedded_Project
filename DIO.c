#include "DIO.h"
#include "tm4c123gh6pm.h"
#include <stdint.h>

void DIO_Init(int32 Port,int32 Pin, int32 Dir){
    switch(Port){
        case PORTA:
        Set_Bit(SYSCTL_RCGCGPIO_R,PORTA);
        while(Get_Bit(SYSCTL_PRGPIO_R,PORTA) == 0){};
        Set_Bit(GPIO_PORTA_CR_R,Pin);
        if (Dir == IN_DIR){
            Clear_Bit(GPIO_PORTA_DIR_R,Pin);
            Set_Bit(GPIO_PORTA_PUR_R,Pin);
        }
        else{
            Set_Bit(GPIO_PORTA_DIR_R,Pin);
        }
        Set_Bit(GPIO_PORTB_DEN_R,Pin);
        break;



        case PORTB:
        Set_Bit(SYSCTL_RCGCGPIO_R,PORTB);
        while(Get_Bit(SYSCTL_PRGPIO_R,PORTB) == 0){};
        Set_Bit(GPIO_PORTB_CR_R,Pin);
        if (Dir == IN_DIR){
            Clear_Bit(GPIO_PORTB_DIR_R,Pin);
            Set_Bit(GPIO_PORTB_PUR_R,Pin);
        }
        else{
            Set_Bit(GPIO_PORTB_DIR_R,Pin);
        }
        Set_Bit(GPIO_PORTB_DEN_R,Pin);
        break;


        case PORTC:
        Set_Bit(SYSCTL_RCGCGPIO_R,PORTC);
        while(Get_Bit(SYSCTL_PRGPIO_R,PORTC) == 0){};
        GPIO_PORTC_LOCK_R = 0x4C4F434B;
        Set_Bit(GPIO_PORTC_CR_R,Pin);
        if (Dir == IN_DIR){
            Clear_Bit(GPIO_PORTC_DIR_R,Pin);
            Set_Bit(GPIO_PORTC_PUR_R,Pin);

        }
        else{
            Set_Bit(GPIO_PORTC_DIR_R,Pin);
        }
        Set_Bit(GPIO_PORTC_DEN_R,Pin);
        break;


        case PORTD:
        Set_Bit(SYSCTL_RCGCGPIO_R,PORTD);
        while(Get_Bit(SYSCTL_PRGPIO_R,PORTD) == 0){};
        GPIO_PORTD_LOCK_R = 0x4C4F434B;
        Set_Bit(GPIO_PORTD_CR_R,Pin);
        if (Dir == IN_DIR){
            Clear_Bit(GPIO_PORTD_DIR_R,Pin);
            Set_Bit(GPIO_PORTD_PUR_R,Pin);
        }
        else{
            Set_Bit(GPIO_PORTD_DIR_R,Pin);
        }
        Set_Bit(GPIO_PORTD_DEN_R,Pin);
        break;

        case PORTE:
        Set_Bit(SYSCTL_RCGCGPIO_R,PORTE);
        while(Get_Bit(SYSCTL_PRGPIO_R,PORTE) == 0){};
        Set_Bit(GPIO_PORTE_CR_R,Pin);
        if (Dir == IN_DIR){
            Clear_Bit(GPIO_PORTE_DIR_R,Pin);
            Set_Bit(GPIO_PORTE_PUR_R,Pin);
        }
        else{
            Set_Bit(GPIO_PORTE_DIR_R,Pin);
        }
        Set_Bit(GPIO_PORTE_DEN_R,Pin);
        break;


        case PORTF:
        Set_Bit(SYSCTL_RCGCGPIO_R,PORTF);
        while(Get_Bit(SYSCTL_PRGPIO_R,PORTF) == 0){};
        GPIO_PORTF_LOCK_R = 0x4C4F434B;
        Set_Bit(GPIO_PORTF_CR_R,Pin);
        if (Dir == IN_DIR){
            Clear_Bit(GPIO_PORTF_DIR_R,Pin);
            Set_Bit(GPIO_PORTF_PUR_R,Pin);
        }
        else{
            Set_Bit(GPIO_PORTF_DIR_R,Pin);
        }
        Set_Bit(GPIO_PORTF_DEN_R,Pin);
        break;
    }
}