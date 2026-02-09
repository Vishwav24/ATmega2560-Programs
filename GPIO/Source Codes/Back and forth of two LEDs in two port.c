#include "Header1.h"
int main()
{
  portf(0xff);
  portk(0xff);
  while(1)
  {
  for(int i=0;i<7;i++)
  {
      highlowf(3<<i);
      delay1(5);
}
highlowf(0x00);
  for(int i=0;i<7;i++)
  {
      highlowk(3<<i);
      delay1(5);
}
highlowk(0x00);
for(int i=6;i>=0;i--)
{
  highlowk(3<<i);
  delay1(5);
}
highlowk(0x00);
for(int i=6;i>=0;i--)
{
  highlowf(3<<i);
  delay1(5);
}
highlowf(0x00);
    }
}
