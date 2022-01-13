#include "DIO.h"
#include "stdint.h"
void DIO_WritePort(int8 port, int8 data)
// Input: port : {PortA,PortB,...,PortF}
// Input  data : {0,1}
// Returns void 
// takes the port number and the data and writes ethier 0 or 1 in the entire ports data register 
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
void DIO_Init_Pin(int8 port, int8 pin, int8 dir)
// Input: port : {PortA,PortB,...,PortF}
// Input: pin : {0,1,2,...}
// Input: direction: {Out_dir,In_dir} 
// Returns void 
// takes the port number and the pin and configures it to be output or input pin
{

    switch (port)
    {
    case PORTA:
        Set_Bit(GPIO_PORTA_CR_R, pin); //setting clock for port selected pin
        if (dir == IN_DIR)
        {
            Clear_Bit(GPIO_PORTA_DIR_R, pin); //setting direction register
            Set_Bit(GPIO_PORTA_PUR_R, pin);   //setting pullup register configuration for this pin in input mode
        }
        else
        {
            Set_Bit(GPIO_PORTA_DIR_R, pin);
            //Set_Bit(GPIO_PORTA_ODR_R, pin);
        }
        Set_Bit(GPIO_PORTA_DEN_R, pin); //digital enabling the pin
        break;
    case PORTB:
        Set_Bit(GPIO_PORTB_CR_R, pin); //setting clock for port selected pin
        if (dir == IN_DIR)
        {
            Clear_Bit(GPIO_PORTB_DIR_R, pin); //setting direction register
            Set_Bit(GPIO_PORTB_PUR_R, pin);   //setting pullup register configuration for this pin in input mode
        }
        else
        {
            Set_Bit(GPIO_PORTB_DIR_R, pin);
            //Set_Bit(GPIO_PORTB_ODR_R, pin);
        }
        Set_Bit(GPIO_PORTB_DEN_R, pin); //digital enabling the pin

        break;
    case PORTC:
        Set_Bit(GPIO_PORTC_CR_R, pin); //setting clock for port selected pin
        if (dir == IN_DIR)
        {
            Clear_Bit(GPIO_PORTC_DIR_R, pin); //setting direction register
            Set_Bit(GPIO_PORTC_PUR_R, pin);   //setting pullup register configuration for this pin in input mode
        }
        else
        {
            Set_Bit(GPIO_PORTC_DIR_R, pin);
            //Set_Bit(GPIO_PORTC_ODR_R, pin);
        }
        Set_Bit(GPIO_PORTC_DEN_R, pin); //digital enabling the pin
        break;
    case PORTD:
        Set_Bit(GPIO_PORTD_CR_R, pin); //setting clock for port selected pin
        if (dir == IN_DIR)
        {
            Clear_Bit(GPIO_PORTD_DIR_R, pin); //setting direction register
            Set_Bit(GPIO_PORTD_PUR_R, pin);   //setting pullup register configuration for this pin in input mode
        }
        else
        {
            Set_Bit(GPIO_PORTD_DIR_R, pin);
            //Set_Bit(GPIO_PORTD_ODR_R, pin);
        }
        Set_Bit(GPIO_PORTD_DEN_R, pin); //digital enabling the pin
        break;
    case PORTE:
        Set_Bit(GPIO_PORTE_CR_R, pin); //setting clock for port selected pin
        if (dir == IN_DIR)
        {
            Clear_Bit(GPIO_PORTE_DIR_R, pin); //setting direction register
            Set_Bit(GPIO_PORTE_PUR_R, pin);   //setting pullup register configuration for this pin in input mode
        }
        else
        {
            Set_Bit(GPIO_PORTE_DIR_R, pin);
            //Set_Bit(GPIO_PORTE_ODR_R, pin);
        }
        Set_Bit(GPIO_PORTE_DEN_R, pin); //digital enabling the pin
        break;
    case PORTF:
        Set_Bit(GPIO_PORTF_CR_R, pin);  //setting clock for port selected pin
        if (dir == IN_DIR)
        {
            Clear_Bit(GPIO_PORTF_DIR_R, pin); //setting direction register
            Set_Bit(GPIO_PORTF_PUR_R, pin);   //setting pullup register configuration for this pin in input mode
        }
        else
        {
            Set_Bit(GPIO_PORTF_DIR_R, pin);
           // Set_Bit(GPIO_PORTF_ODR_R, pin);
        }
        Set_Bit(GPIO_PORTF_DEN_R, pin); //digital enabling the pin
        break;
    default:
        break;
    }
}
void DIO_Init_Port(int8 port)
// Input: port : {PortA,PortB,...,PortF}
// Returns void 
// takes the port number and initializes the clock on this port
{
    switch (port)
    {
    case PORTA:
        Set_Bit(SYSCTL_RCGCGPIO_R, PORTA);           //register clockgating
        while (Get_Bit(SYSCTL_PRGPIO_R, PORTA) == 0) //pireferal ready GPIO register
        {
        }; //busy wait till clock reaches the port
        GPIO_PORTA_LOCK_R = 0x4C4F434B;
        break;
    case PORTB:
        Set_Bit(SYSCTL_RCGCGPIO_R, PORTB);           //register clockgating
        while (Get_Bit(SYSCTL_PRGPIO_R, PORTB) == 0) //pireferal ready GPIO register
        {
        }; //busy wait till clock reaches the port
        GPIO_PORTB_LOCK_R = 0x4C4F434B;

        break;
    case PORTC:
        Set_Bit(SYSCTL_RCGCGPIO_R, PORTC);           //register clockgating
        while (Get_Bit(SYSCTL_PRGPIO_R, PORTC) == 0) //pireferal ready GPIO register
        {
        }; //busy wait till clock reaches the port
        GPIO_PORTC_LOCK_R = 0x4C4F434B;
        break;
    case PORTD:
        Set_Bit(SYSCTL_RCGCGPIO_R, PORTD);           //register clockgating
        while (Get_Bit(SYSCTL_PRGPIO_R, PORTD) == 0) //pireferal ready GPIO register
        {
        }; //busy wait till clock reaches the port
        GPIO_PORTD_LOCK_R = 0x4C4F434B;
        break;
    case PORTE:
        Set_Bit(SYSCTL_RCGCGPIO_R, PORTE);           //register clockgating
        while (Get_Bit(SYSCTL_PRGPIO_R, PORTE) == 0) //pireferal ready GPIO register
        {
        }; //busy wait till clock reaches the port
        GPIO_PORTE_LOCK_R = 0x4C4F434B;
        break;
    case PORTF:
        Set_Bit(SYSCTL_RCGCGPIO_R, PORTF);           //register clockgating
        while (Get_Bit(SYSCTL_PRGPIO_R, PORTF) == 0) //pireferal ready GPIO register
        {
        };                              //busy wait till clock reaches the port
        GPIO_PORTF_LOCK_R = 0x4C4F434B; //unlock the port for using
    default:
        break;
    }
}
void DIO_WritePin(int8 port, int8 pin, int8 data) //preconditions : the port is initialized
// Input: port : {PortA,PortB,...,PortF}
// Input: pin : {0,1,2,...}
// Input: data: {0,1}
// Returns void 
//  takes the port number and specific pin and writes ethier 0 or 1 in the specified pin
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

int8 DIO_ReadPin(int8 port, int8 pin)
// Input: port : {PortA,PortB,...,PortF}
// Input: pin : {0,1,2,...}
// Returns value of the pin {0,1} 
//  takes the port number and specific pin and reads the pin returning its value
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
// Input: port : {PortA,PortB,...,PortF}
// Returns value of the ports data register  
// takes the port number reads it's data register returning it's value
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
// Input: time: Intger
// Returns Void  
// function for artificial delay through busy waiting (not used)
{
    for (int i = 0; i < time; i++)
    {
    }
}

void DIO_TogglePin(int8 Port, int8 Pin){
// Input: port : {PortA,PortB,...,PortF}
// Input: pin : {0,1,2,...}
// Returns void  
// takes the port number and a pin and toggles the value of that pin 
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