#include "DIO.h"
#include "stdint.h"
void Keypad_Init()
{
    for (int i = 0; i < 4; i++)
    {
        DIO_Init(PORTB, i, OUT_DIR);
        DIO_Init(PORTD, i, IN_DIR);
    }
}
int8 Keypad_Read()
{
    int8 values[4][4] = {{'1', '2', '3', '+'},
                       {'4', '5', '6', '-'},
                       {'7', '8', '9', '/'},
                       {'*', '0', '#', '='}};
    for (int i = 0; i < 4; i++)
    {
        DIO_WritePin(PORTB, i, 0);
    }
    int8 column;
    if (DIO_ReadPort(PORTD) == 0xf)
    {
        return 'U';
    }
    else
    {
        for (column = 0; column <4; column++)
        {
          if (DIO_ReadPin(PORTD, column) == 0){
            delay(200);
            if (DIO_ReadPin(PORTD, column) == 0)
               break;
          }
             
        }
    }
    int row;
    for (row = 0; row < 4; row++)
    {
        DIO_WritePort(PORTB, 1);
        DIO_WritePin(PORTB, row,0);
        if (DIO_ReadPin(PORTD, column) == 0)
        {
            delay(200);
            if (DIO_ReadPin(PORTD, column) == 0)
            {
                break;
            }
            //  else return 'U';
        }
    }

    return values[row][column];
}
void DIO_Init(int8 port, int8 pin, int8 dir)
{

    switch (port)
    {
    case PORTA:
        Set_Bit(SYSCTL_RCGCGPIO_R, PORTA);           //register clockgating
        while (Get_Bit(SYSCTL_PRGPIO_R, PORTA) == 0) //pireferal ready GPIO register
        {
        }; //busy wait till clock reaches the port
        GPIO_PORTA_LOCK_R = 0x4C4F434B;
        Set_Bit(GPIO_PORTA_CR_R, pin); //setting clock for port selected pin
        if (dir == IN_DIR)
        {
            Clear_Bit(GPIO_PORTA_DIR_R, pin); //setting direction register
            Set_Bit(GPIO_PORTA_PUR_R, pin);   //setting pullup register configuration for this pin in input mode
        }
        else
        {
            Set_Bit(GPIO_PORTA_DIR_R, pin);
            Set_Bit(GPIO_PORTA_ODR_R, pin);
        }
        Set_Bit(GPIO_PORTA_DEN_R, pin); //digital enabling the pin
        break;
    case PORTB:
        Set_Bit(SYSCTL_RCGCGPIO_R, PORTB);           //register clockgating
        while (Get_Bit(SYSCTL_PRGPIO_R, PORTB) == 0) //pireferal ready GPIO register
        {
        }; //busy wait till clock reaches the port
        GPIO_PORTB_LOCK_R = 0x4C4F434B;
        Set_Bit(GPIO_PORTB_CR_R, pin); //setting clock for port selected pin
        if (dir == IN_DIR)
        {
            Clear_Bit(GPIO_PORTB_DIR_R, pin); //setting direction register
            Set_Bit(GPIO_PORTB_PUR_R, pin);   //setting pullup register configuration for this pin in input mode
        }
        else
        {
            Set_Bit(GPIO_PORTB_DIR_R, pin);
            Set_Bit(GPIO_PORTB_ODR_R, pin);
        }
        Set_Bit(GPIO_PORTB_DEN_R, pin); //digital enabling the pin

        break;
    case PORTC:
        Set_Bit(SYSCTL_RCGCGPIO_R, PORTC);           //register clockgating
        while (Get_Bit(SYSCTL_PRGPIO_R, PORTC) == 0) //pireferal ready GPIO register
        {
        }; //busy wait till clock reaches the port
        GPIO_PORTC_LOCK_R = 0x4C4F434B;
        Set_Bit(GPIO_PORTC_CR_R, pin); //setting clock for port selected pin
        if (dir == IN_DIR)
        {
            Clear_Bit(GPIO_PORTC_DIR_R, pin); //setting direction register
            Set_Bit(GPIO_PORTC_PUR_R, pin);   //setting pullup register configuration for this pin in input mode
        }
        else
        {
            Set_Bit(GPIO_PORTC_DIR_R, pin);
            Set_Bit(GPIO_PORTC_ODR_R, pin);
        }
        Set_Bit(GPIO_PORTC_DEN_R, pin); //digital enabling the pin
        break;
    case PORTD:
        Set_Bit(SYSCTL_RCGCGPIO_R, PORTD);           //register clockgating
        while (Get_Bit(SYSCTL_PRGPIO_R, PORTD) == 0) //pireferal ready GPIO register
        {
        }; //busy wait till clock reaches the port
        GPIO_PORTD_LOCK_R = 0x4C4F434B;
        Set_Bit(GPIO_PORTD_CR_R, pin); //setting clock for port selected pin
        if (dir == IN_DIR)
        {
            Clear_Bit(GPIO_PORTD_DIR_R, pin); //setting direction register
            Set_Bit(GPIO_PORTD_PUR_R, pin);   //setting pullup register configuration for this pin in input mode
        }
        else
        {
            Set_Bit(GPIO_PORTD_DIR_R, pin);
            Set_Bit(GPIO_PORTD_ODR_R, pin);
        }
        Set_Bit(GPIO_PORTD_DEN_R, pin); //digital enabling the pin
        break;
    case PORTE:
        Set_Bit(SYSCTL_RCGCGPIO_R, PORTE);           //register clockgating
        while (Get_Bit(SYSCTL_PRGPIO_R, PORTE) == 0) //pireferal ready GPIO register
        {
        }; //busy wait till clock reaches the port
        GPIO_PORTE_LOCK_R = 0x4C4F434B;
        Set_Bit(GPIO_PORTE_CR_R, pin); //setting clock for port selected pin
        if (dir == IN_DIR)
        {
            Clear_Bit(GPIO_PORTE_DIR_R, pin); //setting direction register
            Set_Bit(GPIO_PORTE_PUR_R, pin);   //setting pullup register configuration for this pin in input mode
        }
        else
        {
            Set_Bit(GPIO_PORTE_DIR_R, pin);
            Set_Bit(GPIO_PORTE_ODR_R, pin);
        }
        Set_Bit(GPIO_PORTE_DEN_R, pin); //digital enabling the pin

        break;
    case PORTF:
        Set_Bit(SYSCTL_RCGCGPIO_R, PORTF);           //register clockgating
        while (Get_Bit(SYSCTL_PRGPIO_R, PORTF) == 0) //pireferal ready GPIO register
        {
        };                              //busy wait till clock reaches the port
        GPIO_PORTF_LOCK_R = 0x4C4F434B; //unlock the port for using
        Set_Bit(GPIO_PORTF_CR_R, pin);  //setting clock for port selected pin
        if (dir == IN_DIR)
        {
            Clear_Bit(GPIO_PORTF_DIR_R, pin); //setting direction register
            Set_Bit(GPIO_PORTF_PUR_R, pin);   //setting pullup register configuration for this pin in input mode
        }
        else
        {
            Set_Bit(GPIO_PORTF_DIR_R, pin);
            Set_Bit(GPIO_PORTF_ODR_R, pin);
        }
        Set_Bit(GPIO_PORTF_DEN_R, pin); //digital enabling the pin
        break;
    default:
        break;
    }
}
void DIO_WritePin(int8 port, int8 pin, int8 data) //preconditions : the port is initialized
{
    switch (port)
    {
    case PORTA:
        if (data == 1)
        {
            Set_Bit(GPIO_PORTA_DATA_R, pin);
        }
        else
        {
            Clear_Bit(GPIO_PORTA_DATA_R, pin);
        }
        break;
    case PORTB:
        if (data == 1)
        {
            Set_Bit(GPIO_PORTB_DATA_R, pin);
        }
        else
        {
            Clear_Bit(GPIO_PORTB_DATA_R, pin);
        }
        break;
    case PORTC:
        if (data == 1)
        {
            Set_Bit(GPIO_PORTC_DATA_R, pin);
        }
        else
        {
            Clear_Bit(GPIO_PORTC_DATA_R, pin);
        }
        break;
    case PORTD:
        if (data == 1)
        {
            Set_Bit(GPIO_PORTD_DATA_R, pin);
        }
        else
        {
            Clear_Bit(GPIO_PORTD_DATA_R, pin);
        }
        break;
    case PORTE:
        if (data == 1)
        {
            Set_Bit(GPIO_PORTE_DATA_R, pin);
        }
        else
        {
            Clear_Bit(GPIO_PORTE_DATA_R, pin);
        }
        break;
    case PORTF:
        if (data == 1)
        {
            Set_Bit(GPIO_PORTF_DATA_R, pin);
        }
        else
        {
            Clear_Bit(GPIO_PORTF_DATA_R, pin);
        }
        break;
    default:
        break;
    }
}
void DIO_WritePort(int8 port, int8 data)
{
    switch (port)
    {
    case PORTA:
        if (data == 1)
        {
            GPIO_PORTA_DATA_R = 0xff;
        }
        else
        {
            GPIO_PORTA_DATA_R = 0x00;
        }
        break;
    case PORTB:
        if (data == 1)
        {
            GPIO_PORTB_DATA_R = 0xff;
        }
        else
        {
            GPIO_PORTB_DATA_R = 0x00;
        }
        break;
    case PORTC:
        if (data == 1)
        {
            GPIO_PORTC_DATA_R = 0xff;
        }
        else
        {
            GPIO_PORTC_DATA_R = 0x00;
        }
        break;
    case PORTD:
        if (data == 1)
        {
            GPIO_PORTD_DATA_R = 0xff;
        }
        else
        {
            GPIO_PORTD_DATA_R = 0x00;
        }
        break;

    case PORTE:
        if (data == 1)
        {
            GPIO_PORTE_DATA_R = 0xff;
        }
        else
        {
            GPIO_PORTE_DATA_R = 0x00;
        }
        break;
    case PORTF:
        if (data == 1)
        {
            GPIO_PORTF_DATA_R = 0xff;
        }
        else
        {
            GPIO_PORTF_DATA_R = 0x00;
        }
        break;

    default:
        break;
    }
}
int8 DIO_ReadPin(int8 port, int8 pin)
{
    int8 Pindata;
    switch (port)
    {
    case PORTA:
        Pindata = Get_Bit(GPIO_PORTA_DATA_R, pin);
        break;
    case PORTB:
        Pindata = Get_Bit(GPIO_PORTB_DATA_R, pin);
        break;
    case PORTC:
        Pindata = Get_Bit(GPIO_PORTC_DATA_R, pin);
        break;
    case PORTD:
        Pindata = Get_Bit(GPIO_PORTD_DATA_R, pin);
        break;
    case PORTE:
        Pindata = Get_Bit(GPIO_PORTE_DATA_R, pin);
        break;
    case PORTF:
        Pindata = Get_Bit(GPIO_PORTF_DATA_R, pin);
        break;
    default:
        break;
    }
    return Pindata;
}
int8 DIO_ReadPort(int8 port)
{
    int8 PortData;
    switch (port)
    {
    case PORTA:
        PortData = GPIO_PORTA_DATA_R;
        break;
    case PORTB:
        PortData = GPIO_PORTB_DATA_R;
        break;
    case PORTC:
        PortData = GPIO_PORTC_DATA_R;
        break;
    case PORTD:
        PortData = GPIO_PORTD_DATA_R;
        break;
    case PORTE:
        PortData = GPIO_PORTE_DATA_R;
        break;
    case PORTF:
        PortData = GPIO_PORTF_DATA_R;
        break;
    default:
        break;
    }
    return PortData;
}
void delay(int time)
{
    for (int i = 0; i < time; i++)
    {
    }
}

void DIO_TogglePin(int8 Port, int8 Pin){

  switch (Port)
    {
    case PORTA:
        Toggle_Bit(GPIO_PORTA_DATA_R,Pin);
        break;

    case PORTB:
        Toggle_Bit(GPIO_PORTB_DATA_R,Pin);
        break;

    case PORTC:
        Toggle_Bit(GPIO_PORTC_DATA_R,Pin);
        break;

    case PORTD:
        Toggle_Bit(GPIO_PORTD_DATA_R,Pin);
        break;

    case PORTE:
        Toggle_Bit(GPIO_PORTE_DATA_R,Pin);
        break;

    case PORTF:
        Toggle_Bit(GPIO_PORTF_DATA_R,Pin);
        break;
    }
}