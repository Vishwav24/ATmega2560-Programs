#include "Port_address.h"

//7Segment for single digit.
void seg1(char io,int num)  //Pass the port and port value(single digit).
{
  char arr[11]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x80};
  if((io == 'a') || (io =='A'))
  {portA_out = arr[num];}
  else if((io == 'b') || (io == 'B'))
  {portB_out = arr[num];}
  else if((io == 'c') || (io == 'C'))
  {portC_out = arr[num];}
  else if((io == 'd') || (io == 'D'))
  {portD_out = arr[num];}
  else if((io == 'e') || (io == 'E'))
  {portE_out = arr[num];}
  else if((io == 'f') || (io == 'F'))
  {portF_out = arr[num];}
  else if((io == 'g') || (io == 'G'))
  {portG_out = arr[num];}
  else if((io == 'h') || (io == 'H'))
  {portH_out = arr[num];}
  else if((io == 'j') || (io == 'J'))
  {portJ_out = arr[num];}
  else if((io == 'k') || (io == 'K'))
  {portK_out = arr[num];}
  else if((io == 'l') || (io == 'L'))
  {portL_out = arr[num];}
}