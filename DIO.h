
#include "types.h"
#include "bitwise_operations.h"
#include "tm4c123gh6pm.h"
//port number values
#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3
#define PORTE 4
#define PORTF 5
//in out values
#define IN_DIR 0
#define OUT_DIR 1
#define One 1
#define Zero 0

void DIO_Init(int8 port,int8 pin,int8 dir);
void DIO_WritePin(int8 port,int8 pin, int8 data);
void DIO_WritePort(int8 port, int8 data);
int8 DIO_ReadPin(int8 port,int8 pin);
int8 DIO_ReadPort(int8 port);
void DIO_TogglePin(int8 Port, int8 Pin);
