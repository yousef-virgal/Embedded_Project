#ifndef SYSTICK
#define SYSTICK
#include <stdint.h>
#include <stdbool.h>
#include "tm4c123gh6pm.h"
#include "bitwise_operations.h"
#define internal 1
#define external 0
void SystickDisable(void);
void SystickEnable (void);
void SystickPeriod(uint32_t ui32Period);
bool Systick_Is_Time_out(void);
void SystickSetClockSource (int source);
#endif