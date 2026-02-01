#define porthlf (*(volatile char *) 0x31)
#define portiof (*(volatile char *)0x30)
#define portiok (*(volatile char *)0x107)
#define porthlk (*(volatile char *) 0x108)
#define port_kread (*(volatile char*)0x106)
#define portioa (*(volatile char *)0x21) 
#define porthla (*(volatile char *)0x22) 
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
//Numbers in Seven Segment
void seg(volatile char num)
{
  char arr[11]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x80};
   highlowf(arr[num]);
}
//Numbers in Seven Seg with dot 
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