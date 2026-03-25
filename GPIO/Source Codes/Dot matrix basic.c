#include "Header1.h"
int main()
{
portf(0xff);
portk(0xff);
while(1)
{
  for(int i=0;i<8;i++)
  {
    highlowk(~((0b00000001)<<i));
    for(int j=0;j<8;j++)
    {
      highlowf(1<<j);
      delay1(2);
    }
  }
}
}