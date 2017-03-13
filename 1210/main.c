
#include "stdio.h"
#include "NUC131.h"
#include "string.h"
#include "TIMER.h"
#include "user_uart.h"
#include "user_sys.h"
#include "buffer.h"


/*
	LEDx				Pin					|  UARTx				Pin								|		Tx	* *	GND -----------|
	----------------				|	 -----------------							|	Ch_Pd	*	*	GPIO2					 |
	LED1				P.B0				|  U0_Rx				P.B0							|		RST	* *	GPIO0          |
	LED2				P.B1				|	 U0_Tx				P.B1							|		VCC	*	*	Rx-------------|
	LED3				P.B13				|	 U1_Rx				P.B4			Pin10		|
	LED tich cuc muc 0.   	|	 U1_Tx				P.B5			Pin11		|
*/

char Buff_Esp[1000];

void delay_s(int s){
	int i=0;
	for(i=0;i<s;i++){
		TIMER_Delay(TIMER0,250000);
		TIMER_Delay(TIMER0,250000);
		TIMER_Delay(TIMER0,250000);
		TIMER_Delay(TIMER0,250000);
	}
}
int main()
{

	SYS_UnlockReg();
	SYS_Init();
	SYS_LockReg();
	/*---------------------------*/
	uart0_init(115200);
	uart1_init(9600);
	/*---------------------------*/	
	printf("Welcome to ESP-8266 project: \r\n");
	uart1_send("AT\r\n");
	TIMER_Delay(TIMER0,250000);
	Buffer_Clr();
	/*---------------------------*/	
//	uart1_send("AT+RST\r\n");
//	delay_s(4);
//	Buffer_Clr();
	/*---------------------------*/	
//	uart1_send("AT+CWJAP=\"Connectify-khiem123\",\"210495fa\"\r\n");
//	delay_s(6);
//	Buffer_Clr();
//	/*---------------------------*/	
//	uart1_send("AT+CIPMUX=1\r\n");
//	delay_s(2);
//	Buffer_Clr();
//	/*---------------------------*/			
//	uart1_send("AT+CIPSTART=\"TCP\",\"128.199.109.89\",80\r\n");
//	delay_s(2);
//	Buffer_Clr();
//	/*---------------------------*/			
//	uart1_send("AT+CIPSEND=73\r\n");
//	delay_s(2);
//	Buffer_Clr();
//	/*---------------------------*/			
//	uart1_send("GET /data/2.5/weather?id=1566083&appid=9ed5f7206c587d1072f40c7c87d58cd7\r\n");
//	delay_s(2);
//	Buffer_Clr();
	while(1){;}
}


void UART1_IRQHandler(void)
{
	char inChar;
	if(UART_IS_RX_READY(UART1))
	{
		inChar = UART_READ(UART1);	
		UART_WRITE(UART0,inChar);
		Buffer_Add(inChar);
	}
}

