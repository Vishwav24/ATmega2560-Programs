#include "Header1.h"
int main()
{
  int flag=0;
  portf(0xff);
  while(1)
  {
  for(int i=2;i<10;i++)
  {
    flag=0;
    for(int j=2;j<i;j++)
    {
        if(i%j==0)
        {
          flag++;
          break;
        }
    }
    if(flag==0)
    {
      seg(i);
      delay1(5);
    }
  }
}
}