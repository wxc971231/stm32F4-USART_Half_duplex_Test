#ifndef __USART_H
#define __USART_H
#include "stdio.h"	
#include "stm32f4xx_conf.h"
#include "sys.h" 

void USART1_Half_Configuration(void);
void USART2_Half_Configuration(void);

#define readOnly(x)	x->CR1 |= 4;	x->CR1 &= 0xFFFFFFF7;		//����x����Ϊֻ����CR1->RE=1, CR1->TE=0
#define sendOnly(x)	x->CR1 |= 8;	x->CR1 &= 0xFFFFFFFB;		//����x����Ϊֻд��CR1->RE=0, CR1->TE=1
				
#endif


