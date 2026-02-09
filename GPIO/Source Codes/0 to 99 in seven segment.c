#include "Header1.h"
int main()
{
  unsigned int c=0;
  portf(0xff);
  portk(0x03);
    while(1)
  {
    for(int i=0;i<10;i++)
    {
      for(int j=0;j<10;j++)
      {
        c=0;
        while(c<50000)
        {
          seg(i);
      highlowk(0x02);
      highlowk(0xff);
     seg(j);
     highlowk(0x01);
     highlowk(0xff);
     c++;
        }
           }
    }
}
}
