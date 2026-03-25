#include "Port_address.h"
//LED chaser
void led_chase(char io)//Just pass the port in argument
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