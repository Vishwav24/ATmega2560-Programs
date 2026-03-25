#include "C:\ATmega2560_Programs\GPIO\Headers\Header1.h"
int main()
{
  portf(0x0f);
  highlowf(0xff);
  portk(0x00);
  porta(0xff);
  while(1)
  {
    highlowa(port_kread);
  }
}