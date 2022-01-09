
#define Set_Bit(Register,bit){Register|=1<<bit;}
#define Clear_Bit(Register,bit){Register &=~(1<<bit);}
#define Get_Bit(Register,bit)((Register&(1<<bit))>>bit)
#define Toggle_Bit(Register,Bit) {Register ^= (1<<Bit);}
#define Set_Register(Register,Data) {Register = Data;}
#define Get_Register(Register) (Register)

