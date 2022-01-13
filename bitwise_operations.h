// common operations that are commonly used 
//sets the value of a Register's bit to 1  
#define Set_Bit(Register,bit){Register|=1<<bit;}
// sets the value of a Register's bit to 0 
#define Clear_Bit(Register,bit){Register &=~(1<<bit);}
// returns the value of Register's bit 
#define Get_Bit(Register,bit)((Register&(1<<bit))>>bit)
// toggles the value of Register's bit (if 1 then sets the value to 0, if 0 then sets the value to 1)
#define Toggle_Bit(Register,Bit) {Register ^= (1<<Bit);}
// set the value of a given Register
#define Set_Register(Register,Data) {Register = Data;}
// returns the complete value of the register
#define Get_Register(Register) (Register)

