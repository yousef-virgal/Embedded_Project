# ifndef MyTimer_h
# define MYTimer_h

# include "types.h"
# include "bitwise_operations.h"
# include "tm4c123gh6pm.h"

#define INTERRUPT 1
#define NOINTERRUPT 0
#define TIMER0 0
#define TIMER1 1
#define TIMER2 2
#define TIMER3 3
#define TIMER4 4
#define TIMER5 5
#define Halfwidth
#define Fullwidth 1

void Timer_Init(int8 timernumber,int8 interruptval);
void Timer_Set(int8 timernumber,uint32 time);
void Timer_Stop(int8 timernumber);
void Timer_Resume(int8 timernumber);

#endif
