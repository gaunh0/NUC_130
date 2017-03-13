#include "user_esp.h"

extern char* Buff_Esp;

void Esp_sendAT(void)
{
	uart1_send("AT\r\n");
//	TIMER_Delay(TIMER0,250000);
}
void Esp_sendRST(void)
{
	uart1_send("AT+RST\r\n");
	delay_s(5);
}
void Esp_checkFwVerison(void)
{
	uart1_send("AT+GRM\r\n");
	delay_s(1);
}
void Esp_checkWifiList(void)
{	
	uart1_send("AT+CWJAP?\r\n");
	delay_s(1);
}
uint8_t Esp_connectWifi(char *id,char* pass)
{
	uart1_send("AT+CWJAP=\"");
	uart1_send(id);
	uart1_send("\",\"");
	uart1_send(pass);
	uart1_send("\"\r\n");
	delay_s(5);
	if(Wait_String(Buff_Esp,"WIFI GOT IP"))
	{
		return 1;
	} 
	else
	{
		return 0;
	}
}
uint8_t Esp_connectServer(char* ip,char* port)
{
	uart1_send("AT+CWJAP=\"TCP\",\"");
	uart1_send(ip);
	uart1_send("\",");
	uart1_send(port);
	uart1_send("\r\n");
	delay_s(2);
	if(Wait_String(Buff_Esp,"OK"))
	{
		return 1;
	} 
	else
	{
		return 0;
	}
}
void Esp_sendCIPMUX(char* mode)
{
	uart1_send("AT+CIPMUX=");
	uart1_send(mode);
	uart1_send("\r\n");
	delay_s(1);
}
void Esp_getData(void)
{
	uint8_t len;
	char kq[75];
	char cipsend[50];
	sprintf(kq,"GET /data/2.5/weather?id=1566083&appid=9ed5f7206c587d1072f40c7c87d58cd7\r\n");
	len=strlen(kq);
	sprintf(cipsend,"AT+CIPSEND=%d\r\n",len);
	uart1_send(cipsend);
	delay_s(2);
	if(Wait_String(Buff_Esp,">"))
	{
		uart1_send(kq);
		if(Wait_String(Buff_Esp,"CLOSED"))
		{
			printf("Da lay duoc data\r\n");
		}
	}
	else
	{
		printf("Khong lay duoc data \r\n");
	}
}

