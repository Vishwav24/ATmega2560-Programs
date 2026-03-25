//All ports and pins can be configured,set and reset.


#include "Port_address.h"
//Delay Function
void delay1(volatile int n)
{for(int i=0;i<(n*100000);i++);}



//Port Configure
void port_config(char io,char val)
{
  if((io == 'a') || (io =='A'))
  {ddrA = val;}
  else if((io == 'b') || (io == 'B'))
  { ddrB = val;}
  else if((io == 'c') || (io == 'C'))
  {ddrC = val;}
  else if((io == 'd') || (io == 'D'))
  {ddrD = val;}
  else if((io == 'e') || (io == 'E'))
  {ddrE = val;}
  else if((io == 'f') || (io == 'F'))
  {ddrF = val;}
  else if((io == 'g') || (io == 'G'))
  {ddrG = val;}
  else if((io == 'h') || (io == 'H'))
  {ddrH = val;}
  else if((io == 'j') || (io == 'J'))
  {ddrJ = val;}
  else if((io == 'k') || (io == 'K'))
  {ddrK = val;}
  else if((io == 'l') || (io == 'L'))
  {ddrL = val;}
}



//Port write
void port_write(char hl,char val)
{
  if((hl == 'a') || (hl == 'A'))
  {portA_out = val;}
  else if((hl == 'b') || (hl == 'B'))
  {portB_out = val;}
  else if((hl == 'c') || (hl == 'C'))
  {portC_out = val;}
  else if((hl == 'd') || (hl == 'D'))
  {portD_out = val;}
  else if((hl == 'e') || (hl == 'E'))
  {portE_out = val;}
  else if((hl == 'f') || (hl == 'F'))
  {portF_out = val;}
  else if((hl == 'g') || (hl == 'G'))
  {portG_out = val;}
  else if((hl == 'h') || (hl == 'H'))
  {portH_out = val;}
  else if((hl == 'j') || (hl == 'J'))
  {portJ_out = val;}
  else if((hl == 'k') || (hl == 'K'))
  {portK_out = val;}
}



//Port read
int port_read(char rd)
{
  if((rd == 'a') || (rd == 'A'))
  {return portA_INPUT;}
  if((rd == 'b') || (rd == 'B'))
  {return portB_INPUT;}
  if((rd == 'c') || (rd == 'C'))
  {return portC_INPUT;}
  if((rd == 'd') || (rd == 'D'))
  {return portD_INPUT;}
  if((rd == 'e') || (rd == 'E'))
  {return portD_INPUT;}
  if((rd == 'f') || (rd == 'F'))
  {return portF_INPUT;}
  if((rd == 'g') || (rd == 'G'))
  {return portG_INPUT;}
  if((rd == 'h') || (rd == 'H'))
  {return portH_INPUT;}
  if((rd == 'j') || (rd == 'J'))
  {return portJ_INPUT;}
  if((rd == 'k') || (rd == 'K'))
  {return portK_INPUT;}
  if((rd == 'l') || (rd == 'L'))
  {return portL_INPUT;}
}



//Pin configure
void pin_config(char io,int pin,char hl)
{
  if((io == 'a') || (io =='A'))
  { if(hl == 1){ddrA |= 1<<pin;}
    else{ddrA &= (~(1<<pin));}
  }
  else if((io == 'b') || (io == 'B'))
  { if(hl == 1){ddrB |= 1<<pin;}
    else{ddrB &= (~(1<<pin));}
  }
  else if((io == 'c') || (io == 'C'))
  { if(hl == 1){ddrC |= 1<<pin;}
    else{ddrC &= (~(1<<pin));}
  }
  else if((io == 'd') || (io == 'D'))
  { if(hl == 1){ddrD |= 1<<pin;}
    else{ddrD &= (~(1<<pin));}
  }
  else if((io == 'e') || (io == 'E'))
  { if(hl == 1){ddrE |= 1<<pin;}
    else{ddrE &= (~(1<<pin));}
  }
  else if((io == 'f') || (io == 'F'))
  { if(hl == 1){ddrF |= 1<<pin;}
    else{ddrF &= (~(1<<pin));}
  }
  else if((io == 'g') || (io == 'G'))
  { if(hl == 1){ddrG |= 1<<pin;}
    else{ddrG &= (~(1<<pin));}
  }
  else if((io == 'h') || (io == 'H'))
  { if(hl == 1){ddrL |= 1<<pin;}
    else{ddrL &= (~(1<<pin));}
  }
  else if((io == 'j') || (io == 'J'))
  { if(hl == 1){ddrH |= 1<<pin;}
    else{ddrH &= (~(1<<pin));}
  }
  else if((io == 'k') || (io == 'K'))
  { if(hl == 1){ddrK |= 1<<pin;}
    else{ddrK &= (~(1<<pin));}
  }
  else if((io == 'l') || (io == 'L'))
  { if(hl == 1){ddrL |= 1<<pin;}
    else{ddrL &= (~(1<<pin));}
  }
}



//Pin Write
void pin_write(char io,int pin,char hl)
{
  if((io == 'a') || (io =='A'))
  { if(hl == 1){portA_out |= 1<<pin;}
    else{portA_out &= (~(1<<pin));}
  }
  else if((io == 'b') || (io == 'B'))
  { if(hl == 1){portB_out |= 1<<pin;}
    else{portB_out &= (~(1<<pin));} 
  }
  else if((io == 'c') || (io == 'C'))
  { if(hl == 1){portC_out |= 1<<pin;}
    else{portC_out &= (~(1<<pin));}
  }
  else if((io == 'd') || (io == 'D'))
  { if(hl == 1){portD_out |= 1<<pin;}
    else{portD_out &= (~(1<<pin));}
  }
  else if((io == 'e') || (io == 'E'))
  { if(hl == 1){portE_out |= 1<<pin;}
    else{portE_out &= (~(1<<pin));}
  }
  else if((io == 'f') || (io == 'F'))
  { if(hl == 1){portF_out |= 1<<pin;}
    else{portF_out &= (~(1<<pin));}
  }
  else if((io == 'g') || (io == 'G'))
  { if(hl == 1){portG_out |= 1<<pin;}
    else{portG_out &= (~(1<<pin));}
  }
  else if((io == 'h') || (io == 'H'))
  { if(hl == 1){portH_out |= 1<<pin;}
    else{portH_out &= (~(1<<pin));}
  }
  else if((io == 'j') || (io == 'J'))
  { if(hl == 1){portJ_out |= 1<<pin;}
    else{portJ_out &= (~(1<<pin));}
  }
  else if((io == 'k') || (io == 'K'))
  { if(hl == 1){portK_out |= 1<<pin;}
    else{portK_out &= (~(1<<pin));}
  }
  else if((io == 'l') || (io == 'L'))
  { if(hl == 1){portL_out |= 1<<pin;}
    else{portL_out &= (~(1<<pin));}
  }
}



//Pin read
int pin_read(char io,int pin)
{
  if((io == 'a') || (io =='A'))
  { int b = ((portA_INPUT) & (1<<pin));
    return b;
  }
  else if((io == 'b') || (io == 'B'))
  { int b = portA_INPUT & (1<<pin);
    return b;
  }
  else if((io == 'c') || (io == 'C'))
  { int b = portA_INPUT & (1<<pin);
    return b;
  }
  else if((io == 'd') || (io == 'D'))
  { int b = portA_INPUT & (1<<pin);
    return b;
  }
  else if((io == 'e') || (io == 'E'))
  { int b = portA_INPUT & (1<<pin);
    return b;
  }
  else if((io == 'f') || (io == 'F'))
  { int b = portA_INPUT & (1<<pin);
    return b;
  }
  else if((io == 'g') || (io == 'G'))
  { int b = portA_INPUT & (1<<pin);
    return b;
  }
  else if((io == 'h') || (io == 'H'))
  { int b = portA_INPUT & (1<<pin);
    return b;
  }
  else if((io == 'j') || (io == 'J'))
  { int b = portA_INPUT & (1<<pin);
    return b;
  }
  else if((io == 'k') || (io == 'K'))
  { int b = ((portK_INPUT) & (1<<pin));
    return b;
  }
  else if((io == 'l') || (io == 'L'))
  { int b = portA_INPUT & (1<<pin);
    return b;
  }
}


//LED chaser
void led_chase(char io)
{
  if((io == 'a') || (io =='A'))
  {for(int i = 0;i<8;i++)
  {
     port_write('a',(1<<i));
    delay1(6);
  }
  }
  else if((io == 'b') || (io == 'B'))
  { for(int i = 0;i<8;i++)
  {
    port_write('b',(1<<i));
    delay1(6);
  }
  }
  else if((io == 'c') || (io == 'C'))
  { for(int i = 0;i<8;i++)
  {
    port_write('c',(1<<i));
    delay1(6);
  }
  }
  else if((io == 'd') || (io == 'D'))
  { for(int i = 0;i<8;i++)
  {
    port_write('d',(1<<i));
    delay1(6);
  }
  }
  else if((io == 'e') || (io == 'E'))
  { for(int i = 0;i<8;i++)
  {
    port_write('e',(1<<i));
    delay1(6);
  }
  }
  else if((io == 'f') || (io == 'F'))
  { for(int i = 0;i<8;i++)
  {
    port_write('f',(1<<i));
    delay1(6);
  }
  }
  else if((io == 'g') || (io == 'G'))
  { for(int i = 0;i<8;i++)
  {
    port_write('g',(1<<i));
    delay1(6);
  }
  }
  else if((io == 'h') || (io == 'H'))
  { for(int i = 0;i<8;i++)
  {
    port_write('h',(1<<i));
    delay1(6);
  }
  }
  else if((io == 'j') || (io == 'J'))
  { for(int i = 0;i<8;i++)
  {
    port_write('j',(1<<i));
    delay1(6);
  }
  }
  else if((io == 'k') || (io == 'K'))
  { for(int i = 0;i<8;i++)
  {
    port_write('k',(1<<i));
    delay1(6);
  }
  }
  else if((io == 'l') || (io == 'L'))
  { for(int i = 0;i<8;i++)
  {
    port_write('l',(1<<i));
    delay1(6);
  }
  }
}