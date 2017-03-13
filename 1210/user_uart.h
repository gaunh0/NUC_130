#ifndef __USER_UART_H_
#define __USER_UART_H_


#include "stdio.h"
#include "NUC131.h"
#include "string.h"

void uart0_init(uint32_t baud);
void uart1_init(uint32_t baud);
void uart1_send(char* _chuoi);
void send_char(char ch);

#endif
