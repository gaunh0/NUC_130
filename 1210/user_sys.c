#include "user_sys.h"

void SYS_Init(void)
{
    /*---------------------------------------------------------------------------------------------------------*/
    /* Init System Clock                                                                                       */
    /*---------------------------------------------------------------------------------------------------------*/
	
    /* Enable Internal RC 22.1184MHz clock */
    CLK->PWRCON |= CLK_PWRCON_OSC22M_EN_Msk;
	
    /* Waiting for Internal RC clock ready */
    while(!(CLK->CLKSTATUS & CLK_CLKSTATUS_OSC22M_STB_Msk));
	
    /* Switch HCLK clock source to Internal RC and and HCLK source divide 1 */
    CLK->CLKSEL0 &= ~CLK_CLKSEL0_HCLK_S_Msk;
    CLK->CLKSEL0 |= CLK_CLKSEL0_HCLK_S_HIRC;
    CLK->CLKDIV &= ~CLK_CLKDIV_HCLK_N_Msk;
    CLK->CLKDIV |= CLK_CLKDIV_HCLK(1);
	
    /* Enable external XTAL 12MHz clock */
    CLK->PWRCON |= CLK_PWRCON_XTL12M_EN_Msk;
	
    /* Waiting for external XTAL clock ready */
    while(!(CLK->CLKSTATUS & CLK_CLKSTATUS_XTL12M_STB_Msk));
	
    /* Set core clock as PLL_CLOCK from PLL */
    CLK->PLLCON = PLLCON_SETTING;
    while(!(CLK->CLKSTATUS & CLK_CLKSTATUS_PLL_STB_Msk));
    CLK->CLKSEL0 &= (~CLK_CLKSEL0_HCLK_S_Msk);
    CLK->CLKSEL0 |= CLK_CLKSEL0_HCLK_S_PLL;
	
    /* Update System Core Clock */
    /* User can use SystemCoreClockUpdate() to calculate PllClock, SystemCoreClock and CycylesPerUs automatically. */
    //SystemCoreClockUpdate();
    PllClock        = PLL_CLOCK;            // PLL
    SystemCoreClock = PLL_CLOCK / 1;        // HCLK
    CyclesPerUs     = PLL_CLOCK / 1000000;  // For SYS_SysTickDelay()
	
    /* Enable UART & TIMER0 module clock */
    CLK->APBCLK |= CLK_APBCLK_UART0_EN_Msk
								| CLK_APBCLK_UART1_EN_Msk
								| CLK_APBCLK_TMR0_EN_Msk;
		
    /* Select UART & TIMER0 module clock source */
    CLK->CLKSEL1 &= ~(CLK_CLKSEL1_UART_S_Msk|CLK_CLKSEL1_TMR0_S_Msk);
    CLK->CLKSEL1 |= CLK_CLKSEL1_UART_S_HXT
								 |CLK_CLKSEL1_TMR0_S_HXT;
	
    /*---------------------------------------------------------------------------------------------------------*/
    /* Init I/O Multi-function                                                                                 */
    /*---------------------------------------------------------------------------------------------------------*/
	
    /* Set GPB multi-function pins for UART0, UART1 RXD and TXD */
    SYS->GPB_MFP &= ~(SYS_GPB_MFP_PB0_Msk | SYS_GPB_MFP_PB1_Msk
									|SYS_GPB_MFP_PB4_Msk | SYS_GPB_MFP_PB5_Msk);
    SYS->GPB_MFP |= SYS_GPB_MFP_PB0_UART0_RXD | SYS_GPB_MFP_PB1_UART0_TXD
									|SYS_GPB_MFP_PB4_UART1_RXD | SYS_GPB_MFP_PB5_UART1_TXD;
}
