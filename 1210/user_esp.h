#ifndef __USER_ESP_
#define __USER_ESP_

#include "stdio.h"
#include "NUC131.h"
#include "string.h" 
#include "buffer.h"
#include "user_uart.h"
#include "stdlib.h"
#include "TIMER.h"

void delay_s(int s);
void Esp_sendAT(void);
void Esp_sendRST(void);
void Esp_checkFwVerison(void);
void Esp_checkWifiList(void);
uint8_t Esp_connectWifi(char *id,char* pass);
uint8_t Esp_connectServer(char* ip,char* port);
void Esp_sendCIPMUX(char* mode);
void Esp_getData(void);

#endif
