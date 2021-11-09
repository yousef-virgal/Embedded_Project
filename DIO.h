#include "bitwise_operations.h"
#include "types.h"

#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3
#define PORTE 4
#define PORTF 5

#define IN_DIR 0
#define OUT_DIR 1
#define One 1
#define Zero 0
void DIO_Init(int8 Port,int8 pin, int8 dir);
void DIO_WritePin(int8 Port,int8 Pin,int8 Data);
void DIO_Write_Port(int8 Port, int8 Data);
int8 DIO_ReadPin(int8 Port,int8 pin);
int8 DIO_ReadPort(int8 Port);