#include "DIO.h"
int main()
{
  DIO_Init(PORTF,1,OUT_DIR);
  DIO_Init(PORTF,2,OUT_DIR);
  DIO_Init(PORTF,3,OUT_DIR);
  
  while(1){
    DIO_Write_Port(PORTF,Zero);
    DIO_WritePin(PORTF,1,One);
    for(int i =0 ;i<1000000;i++){}
    DIO_Write_Port(PORTF,Zero);
    DIO_WritePin(PORTF,2,One);
    for(int i =0 ;i<1000000;i++){}
    DIO_Write_Port(PORTF,Zero);
    DIO_WritePin(PORTF,3,One);
    for(int i =0 ;i<1000000;i++){}
    
  }
}
