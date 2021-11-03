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

void DIO_Init(int32 Port,int32 pin, int32 dir);