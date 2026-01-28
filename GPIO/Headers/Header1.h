#define porthlf (*(volatile char *) 0x31)
#define portiof (*(volatile char *)0x30)
#define portiok (*(volatile char *)0x107)
#define porthlk (*(volatile char *) 0x108)
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
void delay1(int n)
{
  for(volatile long i=0;i<(n*100000);i++);
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
//Numbers in Seven Segment
void seg(volatile char num)
{
  char arr[11]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x80};
   highlowf(arr[num]);
}