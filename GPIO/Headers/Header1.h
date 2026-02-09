#define porthlf (*(volatile char *) 0x31)
#define portiof (*(volatile char *)0x30)
#define portiok (*(volatile char *)0x107)
#define porthlk (*(volatile char *) 0x108)
#define port_kread (*(volatile char*)0x106)
#define port_cread (*(volatile char *)0x026)
#define portioa (*(volatile char *)0x21) 
#define porthla (*(volatile char *)0x22) 
#define portioc (*(volatile char *)0x27)
#define porthlc (*(volatile char *)0x28)
#define portiob (*(volatile char *)0x24)
#define porthlb (*(volatile char *)0x25)
//Data Register Port F
void highlowf(volatile char status)
{
  porthlf=status;
  }
// DDR Port F
void portf(char inout)
{
  portiof=inout;
}
//Delay
void delay1(float n)
{
  for(volatile double i=0;i<(n*10000);i++);
}
//Data register Port k
void highlowk(volatile char status)
{
  porthlk=status;
}
//DDR Port k
void portk(volatile char inout)
{
  portiok=inout;
}
//DDR port c
void portc(volatile char io)
{
  portioc = io;
}
// Data register port c
void highlowc(volatile char hl)
{
  porthlc = hl;
}
//DDr Port a
void porta(volatile char inout)
{
  portioa = inout;
}
//Data Register a
void highlowa(volatile char hl)
{
  porthla = hl;
}
//DDR Port b
void portb(volatile char io)
{
  portiob = io;
}
//Data register b
void highlowb(volatile char hl)
{
  porthlb = hl;
}
//Numbers in Seven Segment porf
void seg(volatile char num)
{
  char arr[11]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x80};
   highlowf(arr[num]);
}
//Numbers in Seven Segment portb
void segb(volatile char num)
{
  char arr[11]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x80};
   highlowb(arr[num]);
}
//Numbers in Seven Seg with dot in portf 
void segdot(volatile char num)
{
  char arrr[11]={0xBF, 0x86, 0xDB, 0xCF, 0xE6, 0xED, 0xFD, 0x87, 0xFF, 0xEF
};
  highlowf(arrr[num]);
}
//Portk read
unsigned char portkread()
{
  return port_kread;
}
//7seg and Display
void segseven(volatile char seg,volatile char seg2)
{
  char arr[3][3]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f};
  highlowb(arr[seg][seg2]);
}
//For calculator in keypad
int keyp()
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
          a[0] = sum;
          a[1] = 0;
          sum =0;
        } 
       else if((port_cread==0x02)&&(port_kread==0x08))
        {
          a[0] = sum;
          a[1]=1;
          sum = 0;
        }
        else if((port_cread==0x04)&&(port_kread==0x08))
        {
          a[0] = sum;
          a[1]=2;
          sum = 0;
        }
        else if((port_cread==0x08)&&(port_kread==0x08))
        {
          a[0] = sum;
          a[1]=3;
          sum = 0;
        } 
        else if(port_cread==0x01)
        {  
          sum=(sum*10)+((port_kread>>1)+1);
        }    
        else if(port_cread == 0x02)
        {
          sum=(sum*10)+((port_kread>>1)+4);
        }
        else if(port_cread == 0x04)
        {
          sum=(sum*10)+((port_kread>>1)+7);
        }
         else if((port_cread==0x08)&&(port_kread==0x02))
        {
          sum=(sum*10);
        }
        else if((port_cread==0x08)&&(port_kread==0x04))
        {
          if(a[1]==0)
          {
            a[2] = sum;
            int sum1 = a[0]+a[2];
            return sum1;
          }
          else if(a[1]==1)
          {
            a[2] = sum;
            int sum1 = a[0] - a[2];
            return sum1;
          }
          else if(a[1]==2)
          {
            a[2] = sum;
            int sum1 = a[0] * a[2];
            return sum1;
          }
          else if(a[1]==3)
          {
            a[2] = sum;
            int sum1 = a[0] / a[2];
            return sum1;
          }
           t=0;
          sum = 0;
        }
        delay1(2);
        highlowc(0);
      }
      }
    }
}