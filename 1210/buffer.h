#ifndef __BUFFER_
#define __BUFFER_

#include "stdio.h"
#include "NUC131.h"
#include "string.h"

extern char Buff_Esp[1000];

void Buffer_Add(char c);
void Buffer_Clr(void);
uint8_t Wait_String(char* taget,char* str); 

#endif
