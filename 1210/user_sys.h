#ifndef __USER_SYS_
#define __USER_SYS_

#include "stdio.h"
#include "NUC131.h"


#define PLLCON_SETTING  CLK_PLLCON_50MHz_HXT
#define PLL_CLOCK       50000000

void SYS_Init(void);

#endif
