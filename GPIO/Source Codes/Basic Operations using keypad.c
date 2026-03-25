 #include "C:\ATmega2560_Programs\GPIO\Headers\Header1.h"
int main()
{
  int a[3];
  portf(0xff);
  portk(0x00);
  portc(0xff);
  porta(0xff);
  portb(0xff);
  int t=0,sum = 0;
  while(1)
  {
    for(int i=0;i<4;i++)
    {
      highlowf(1<<i);
      highlowa(port_kread);
      if(port_kread!=0)
      {
        highlowc(1<<i); 
        if((port_cread==0x01)&&(port_kread==0x08))
        {
          a[t] = 0;
          delay1(2);
          t++;
        } 
       else if((port_cread==0x02)&&(port_kread==0x08))
        {
          a[t]=1;
          delay1(2);
          t++;
        }
        else if((port_cread==0x04)&&(port_kread==0x08))
        {
          a[t]=2;
          delay1(2);
          t++;
        }
        else if((port_cread==0x08)&&(port_kread==0x08))
        {
          a[t]=3;
          delay1(2);
          t++;
        } 
        else if(port_cread==0x01)
        {  
          a[t]=(port_kread>>1)+1;
          delay1(2);
          t++;
        }    
        else if(port_cread == 0x02)
        {
          a[t] = (port_kread>>1)+4;
          delay1(2);
          t++;
        }
        else if(port_cread == 0x04)
        {
          a[t] = (port_kread>>1)+7;
          delay1(2);
          t++;
        }
        else if((port_cread==0x08)&&(port_kread==0x04))
        {
          if(a[1]==0)
          {
            segb(a[0]+a[2]);
          }
          else if(a[1]==1)
          {
            segb(a[0]-a[2]);
          }
          else if(a[1]==2)
          {
            segb(a[0]*a[2]);
          }
          else if(a[1]==3)
          {
            segb(a[0]/a[2]);
          }
           t=0;
          sum = 0;
        }
        else
        {
          a[t]=0;
          delay1(2);
          t++;
        }
        delay1(2);
        highlowc(0);
      }
      }
    }
}
