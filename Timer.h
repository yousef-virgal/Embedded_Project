# ifndef Timer_h
# define Timer_h

# include "types.h"
# include "bitwise_operations.h"
# include "tm4c123gh6pm.h"

#define INTERRUPT 1
#define INTERRUPT 0
#define TIMER0 0
#define TIMER1 1
#define TIMER2 2
#define TIMER3 3
#define TIMER4 4
#define TIMER5 5
#define Halfwidth
#define Fullwidth 1

void timer_init(int8 timernumber, int32 prescaleval,int8 interruptval);
void timer_set(int8 timernumber,int32 time);
void stop_timer(int8 timernumber);
void resume_timer(int8 timernumber);

#endif
