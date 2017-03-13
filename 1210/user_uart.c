#include "user_uart.h"


void uart0_init(uint32_t baud)
{
	SYS_ResetModule(UART0_RST);
	UART_Open(UART0,baud);
	//UART_EnableInt(UART0,UART_IER_RDA_IEN_Msk );
}
void uart1_init(uint32_t baud)
{
	SYS_ResetModule(UART1_RST);
	UART_Open(UART1,baud);
	UART_EnableInt(UART1,UART_IER_RDA_IEN_Msk );
    
}
void uart1_send(char* _chuoi)
{
	while(*_chuoi)
	{
		send_char(*_chuoi++);
	}
}
void send_char(char ch)
{
	while((UART1->FSR & UART_FSR_TE_FLAG_Msk)==0)
	{;}
	UART1->THR = ch;
}
