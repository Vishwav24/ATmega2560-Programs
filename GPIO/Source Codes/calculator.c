#include "C:\ATmega2560_Programs\GPIO\Headers\Header1.h"
int main()
{
  while(1)
  {
  int k = keyp(),f=0,a[100],i=0;
  while(k!=0)
  {
    int b = k%10;
    a[f] = b;
    k = k/10;
    f++;
  }
  f = f-1;
  while(f>=0)
  {
    segb(a[f]);
    delay1(5);
    f--;
  }
  }
}