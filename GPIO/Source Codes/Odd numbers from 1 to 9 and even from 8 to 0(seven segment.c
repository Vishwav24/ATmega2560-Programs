// use #include "Header1.h"
int main()
{
  portf(0xff);
  while(1)
  {
  for(int i=9;i>=0;i--)
  {
    if(i%2==0)
    {
  seg(i);
  delay1(3);
    }
  }
  for(int i=0;i<9;i++)
  {
    if(i%2==0)
    {
  seg(i);
  delay1(3);
    }
  }
  }
}