// use #include "Header1.h"
int main()
{
  int c=0;
  while(1)
  {
   portf(0xff);
  for(int i=0;i<10;i++)
  {
    
    for(int j=0;j<10;j++)
    {
      c=0;
     while(c<400)
      {
      portk(0x02);
      highlowk(0x02);
      seg(i);
      _delay_ms(2);
      portk(0x01);
      highlowk(0x01);
      seg(j);
      _delay_ms(2);
      c++;
     }
    }
  }
  }
}