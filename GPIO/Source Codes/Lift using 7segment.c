#include "Header1.h"
int main()
{
  int a=0;
  portf(0xff);
  portk(0x00);
  highlowk(0xff);
  int b=0;
  while(1)
  {
    b=portkread();
  if(b==0xf7)
{
  seg(1);
    if(a<3)
    {
    for(int i=a;i<=3;i++)
    {
      seg(i);
      delay1(6);
    }
    }
    seg(3);
    a=3;
  }
   if(b==0xfb)
  {
    if(a<2)
    {
    for(int i=a;i<=2;i++)
    {
      seg(i);
      delay1(6);

    }
    }
    if(a>2)
    {
      for(int i=3;i>=3;i--)
      {
        seg(i);
        delay1(6);

      }
    }
    seg(2);
    a=2;
  }
  if(b==0xfd)
  {
    if(a>1)
    {
      for(int i=a;i>=1;i--)
      {
        seg(i);
        delay1(6);

      }
    }
    if(a<1)
    {
      for(int i=0;i<=1;i++)
      {
        seg(i);
        delay1(6);

      }
    }
    seg(1);
    a=1;
  }
  if(b==0xfe)
  {
    if(a>0)
    {
      for(int i=a;i>=0;i--)
      {
        seg(i);
        delay1(6);

      }
    }
    seg(1);
    a=1;
  }
  }
}