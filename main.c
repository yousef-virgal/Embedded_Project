#include "DIO.h"
void delay(int32 counter);
int main()
{
  DIO_Init(PORTF,0,IN_DIR);
  DIO_Init(PORTF,1,OUT_DIR);
  DIO_Init(PORTF,2,OUT_DIR);
  DIO_Init(PORTF,3,OUT_DIR);
  DIO_Init(PORTF,4,IN_DIR);
//  
//  enum states {white = 0, red = 1,green = 2,blue = 3};
//  enum states state = white;
//  DIO_WritePin(PORTF,1,One);
//  DIO_WritePin(PORTF,2,One);
//  DIO_WritePin(PORTF,3,One);
//  while(1){
//    switch(state){
//    case white:
//      if(~DIO_ReadPin(PORTF,0) & 0x01){
//        delay(1000000);
//        if(~DIO_ReadPin(PORTF,0) & 0x01){
//        state = red;
//        DIO_WritePin(PORTF,2,Zero);
//        DIO_WritePin(PORTF,3,Zero);
//        }
//        
//      }
//      else if(~DIO_ReadPin(PORTF,4) & 0x01){
//        delay(1000000);
//        if(~DIO_ReadPin(PORTF,4) & 0x01){
//        state = blue;
//        DIO_WritePin(PORTF,1,Zero);
//        DIO_WritePin(PORTF,3,Zero);
//        }
//      }
//      break;
//      
//    case red:
//      if(~DIO_ReadPin(PORTF,0) & 0x01){
//        delay(1000000);
//        if(~DIO_ReadPin(PORTF,0) & 0x01){
//        state = green;
//        DIO_WritePin(PORTF,3,One);
//        DIO_WritePin(PORTF,1,Zero);
//        }
//      }
//      else if(~DIO_ReadPin(PORTF,4) & 0x01){
//        delay(1000000);
//        if(~DIO_ReadPin(PORTF,4) & 0x01){
//        state = white;
//        DIO_WritePin(PORTF,3,One);
//        DIO_WritePin(PORTF,2,One);
//        }
//      }
//      break;
//    case green:
//      
//      if(~DIO_ReadPin(PORTF,0) & 0x01){
//        delay(1000000);
//        if(~DIO_ReadPin(PORTF,0) & 0x01){
//        state = blue;
//        DIO_WritePin(PORTF,3,Zero);
//        DIO_WritePin(PORTF,2,One);
//        }
//      }
//      else if(~DIO_ReadPin(PORTF,4) & 0x01){
//        delay(1000000);
//        if(~DIO_ReadPin(PORTF,4) & 0x01){
//        state = red;
//        DIO_WritePin(PORTF,3,Zero);
//        DIO_WritePin(PORTF,1,One);
//        }
//      }
//      break;
//    case blue:
//      if(~DIO_ReadPin(PORTF,0) & 0x01){
//        delay(1000000);
//        if(~DIO_ReadPin(PORTF,0) & 0x01){
//        state = white;
//        DIO_WritePin(PORTF,1,One);
//        DIO_WritePin(PORTF,3,One);
//        }
//      }
//      else if(~DIO_ReadPin(PORTF,4) & 0x01){
//        delay(1000000);
//        if(~DIO_ReadPin(PORTF,4) & 0x01){
//        state = green;
//        DIO_WritePin(PORTF,2,Zero);
//        DIO_WritePin(PORTF,3,One);
//        }
//      }
//      break;
//    }
//  }
  
  while(1){
    
    if((~DIO_ReadPin(PORTF,0) & 0x01) && (~DIO_ReadPin(PORTF,4) & 0x01)){
      
      if((~DIO_ReadPin(PORTF,0) & 0x01) && (~DIO_ReadPin(PORTF,4) & 0x01)){
      DIO_Write_Port(PORTF,Zero);
      DIO_WritePin(PORTF,3,One);
      }
    }
    else if(~DIO_ReadPin(PORTF,0) & 0x01){
      delay(3000);
      if(~DIO_ReadPin(PORTF,0) & 0x01){
      DIO_Write_Port(PORTF,Zero);
      DIO_WritePin(PORTF,1,One);
      }
    }
    else if(~DIO_ReadPin(PORTF,4) & 0x01){
      delay(3000);
      if(~DIO_ReadPin(PORTF,4) & 0x01){
      DIO_Write_Port(PORTF,Zero);
      DIO_WritePin(PORTF,2,One);
      }
    }
    else{
    DIO_Write_Port(PORTF,Zero);
    }
  }
}
void delay(int32 counter){
  for(int i =0 ;i<counter/4;i++){
  }
}