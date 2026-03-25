// use Header1.h
#include "Header1.h"
//For calculator in keypad.Returns the value.
//Keep portf as output and k as input from keypad.
//The value returned from the calculator can be used for any purpose.
int keyp() 
{
  long long a[3];
  portf(0xff);
  portk(0x00);
  portb(0xff);
  int t=0,sum = 0;
  while(1)
  {
    for(int i=0;i<4;i++)
    {
      highlowf(1<<i);
      if(port_kread!=0)
      { 
        if((port_fread==0x01)&&(port_kread==0x08))
        {
          a[0] = sum;
          a[1] = 0;
          sum =0;
        } 
       else if((port_fread==0x02)&&(port_kread==0x08))
        {
          a[0] = sum;
          a[1]=1;
          sum = 0;
        }
        else if((port_fread==0x04)&&(port_kread==0x08))
        {
          a[0] = sum;
          a[1]=2;
          sum = 0;
        }
        else if((port_fread==0x08)&&(port_kread==0x08))
        {
          a[0] = sum;
          a[1]=3;
          sum = 0;
        } 
        else if((port_fread==0x08)&&(port_kread==0x01))
        {
          a[0] = sum;
          a[1] = 4;
          sum = 0;
        }
        else if(port_fread==0x01)
        {  
          sum=(sum*10)+((port_kread>>1)+1);
        }    
        else if(port_fread == 0x02)
        {
          sum=(sum*10)+((port_kread>>1)+4);
        }
        else if(port_fread == 0x04)
        {
          sum=(sum*10)+((port_kread>>1)+7);
        }
         else if((port_fread==0x08)&&(port_kread==0x02))
        {
          sum=(sum*10);
        }
        else if((port_fread==0x08)&&(port_kread==0x04))
        {
          if(a[1]==0)
          {
            a[2] = sum;
            long long sum1 = a[0]+a[2];
            sum = 0;
            return sum1;
          }
          else if(a[1]==1)
          {
            a[2] = sum;
            long long sum1 = a[0] - a[2];
            sum = 0;
            return sum1;
          }
          else if(a[1]==2)
          {
            a[2] = sum;
            long long sum1 = a[0] * a[2];
            sum= 0;
            return sum1;
          }
          else if(a[1]==3)
          {
            a[2] = sum;
            long long sum1 = a[0] / a[2];
            sum = 0;
            return sum1;
          }
          else if(a[1]==4)
          {
            a[2] = sum;
            long long sum1 = a[0] % a[2];
            sum = 0;
            return sum1;
          }
        }
        delay1(2);
        highlowc(0);
      }
      }
    }
}