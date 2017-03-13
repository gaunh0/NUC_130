#include "buffer.h"

void Buffer_Add(char c)
{
	uint16_t len=0;	
	len=strlen(Buff_Esp);	   
	Buff_Esp[len]=c;
	Buff_Esp[len+1]='\0';
}
void Buffer_Clr(void)
{
	int len = strlen(Buff_Esp);
	int i ;
	for(i =0;i<len;i++)
	{
		Buff_Esp[i] = 0;
	}	
	Buff_Esp[0] = '\0';
}
uint8_t Wait_String(char* taget,char* str)
{
	uint8_t ret_val=0;
	if(strstr(taget,str))
		{
			ret_val = 1;
		}
	return ret_val;
}	
