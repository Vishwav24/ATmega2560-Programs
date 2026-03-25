#define A 0
#define B 1
#define C 2
#define D 3
#define E 4
#define F 5
#define G 6
#define H 7
#define J 8
#define K 9
#define L 10
#define TCCR1A (*(volatile unsigned char*)0x80)
#define TCCR1B (*(volatile unsigned char*)0x81)
#define TCNT1 (*(volatile unsigned int*)0x84)
#define TIFR1 (*(volatile unsigned int*)0x36)


uint8_t *port[11] = {(volatile uint8_t *)0x21,(volatile uint8_t *)0x24,(volatile uint8_t *)0x27,(volatile uint8_t *)0x2A,
	              (volatile uint8_t *)0x2D,(volatile uint8_t *)0x30,(volatile uint8_t *)0x33,(volatile uint8_t *)0x101,
							  (volatile uint8_t *)0x104,(volatile uint8_t *)0x107,(volatile uint8_t *)0x10A};
uint8_t *pin[11]  = {(volatile uint8_t *)0x22,(volatile uint8_t *)0x25,(volatile uint8_t *)0x28,(volatile uint8_t *)0x2B,
	              (volatile uint8_t *)0x2E,(volatile uint8_t *)0x31,(volatile uint8_t *)0x34,(volatile uint8_t *)0x102,
							  (volatile uint8_t *)0x105,(volatile uint8_t *)0x108,(volatile uint8_t *)0x10B};
uint8_t *pread[11] = {(volatile uint8_t *)0x20,(volatile uint8_t *)0x23,(volatile uint8_t *)0x26,(volatile uint8_t *)0x29,
	                   (volatile uint8_t *)0x2C,(volatile uint8_t *)0x2F,(volatile uint8_t *)0x32,(volatile uint8_t *)0x100,
						         (volatile uint8_t *)0x103,(volatile uint8_t *)0x106,(volatile uint8_t *)0x109};

void port_set(uint8_t x,volatile uint8_t x1)
{
  *port[x] = x1;
}


void port_write(uint8_t x,volatile uint8_t x1)
{
  *pin[x] = x1;
}


uint8_t port_read(uint8_t x)
{
  return *pread[x];
}


void pin_set(uint8_t x,uint8_t x1,volatile uint8_t x2)
{
  if(x2==1) *port[x] |= (1<<x1);
  else *port[x] &= (~(1<<x1));
}


void pin_write(uint8_t x,uint8_t x1,volatile uint8_t x2)
{
  if(x2==1) *pin[x] |= (1<<x1);
  else *pin[x] &= (~(1<<x1));
}


const volatile uint8_t a[10] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
	

// Function to Display Single Digit value 
// ***MUST CONFIGURE the PORT that is used during the SETUP
void seg_1(uint8_t x, uint8_t val) // disp_1d(port_name,value)
{   
	*pin[x] = a[val];
}



void seg_2(uint8_t x, uint8_t y, uint16_t val) //disp_2d(port_name, selection_port_name, value)
{
	volatile long b = 0;
	*pin[y] = 0xFF;
//	while(b<100000)
	//{
		*pin[x] = a[val%10];
		*pin[y] = ~0x02;
    for(volatile int i=0;i<500;i++);
		*pin[y] = 0x03;
		*pin[x] = a[val/10];
		*pin[y] = ~0x01;
    for(volatile int i=0;i<500;i++);
		*pin[y] = 0x03;
		b++;
	//}
}


void seg_3(uint8_t x, uint8_t y, uint16_t val) //disp_2d(port_name, selection_port_name, value)
{
	volatile long b = 0;
	*pin[y] = 0xFF;
	//while(b<100000)
	//{
		*pin[x] = a[val%10];
		*pin[y] = ~0x04;
    for(volatile int i=0;i<500;i++);
		*pin[y] = 0x07;
		*pin[x] = a[(val/10)%10];
		*pin[y] = ~0x02;
    for(volatile int i=0;i<500;i++);
		*pin[y] = 0x07;
    *pin[x] = a[(val/100)%10];
    *pin[y] = ~0x01;
    for(volatile int i=0;i<500;i++);
    *pin[y] = 0x07;
		b++;
	//}
}


/******                This Library contains functions to scan a 4x4 Keypad and Returns 
                             scanned Position's Value from the keypad[][] Array                       ******/


                  /****** Feel free to modify the keypad[][] array to suit your needs ******/     
                  
                  /****** Here, ROWS are used as INPUTS and COLUMNS are used as OUTPUTS ******/
                  
                           /****** MUST PULL-DOWN the ROW Pins EXTERNALLY! ******/
                  

const int keypad[4][4] = {
	{ 1, 2, 3, 0 },
	{ 4, 5, 6, 0 },
	{ 7, 8, 9, 0 },
	{ 0, 0, 0, 0 }
};


// Function to Scan the Keypad and Return the Scanned Position's Value from the keypad[][] Array
// ***MUST CONFIGURE the PORTS that is used during the SETUP
uint8_t kp_scan(uint8_t x, uint8_t y)// kp_scan(row_port, column_port)
{
	int b;
	while(1)
	{
		for (int i=0;i<4;i++)
		{
			*port[y] = (1<<i);
			if (*pread[x]!=0x00)
			{
				b = *pread[x];
				if(*pread[x]==8)
				{
					b--;
				}
				return keypad[i][b/2];
			}
		}
	}
}



//timer  1ms
void delay_ms(volatile int n)
{
for(volatile int i=0;i<n*1000;i++)
    {
      TCCR1A = 0;
      TCCR1B = 0x02;
      TCNT1 = 63536;
      while(!(TIFR1 & 0x01));
      TIFR1 = 0x01;
    }
}