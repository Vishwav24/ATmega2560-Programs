#include "Header1.h"
int main()
{
  portf(0xff);
  portk(0x00);
  porta(0xff);
  portc(0xff);
  portb(0xff);

  int keypad[4][4] = {
  { 1, 2, 3, 0 },
  { 4, 5, 6, 0 },
  { 7, 8, 9, 0 },
  { '*', 0, '#', 'D' }
},a[3],b[3];
  while(1)
  {

  for(int i=0;i<4;i++)
  {
    highlowf(1<<i);
    highlowa(port_kread);
    if(port_kread!=0)
    {
      highlowc(1<<i);
      if(port_cread==0x01)
      { 
        segb(keypad[i][port_kread>>1]);
      }
      if(port_cread==0x02)
      {
        segb(keypad[i][port_kread>>1]);
      }
      if(port_cread==0x04)
      {
        segb(keypad[i][port_kread>>1]);
      }
      if(port_cread==0x08)
      {
        segb(keypad[i][port_kread>>1]);
      }
      delay1(2);
      highlowc(0);
    }
  }
  }
}