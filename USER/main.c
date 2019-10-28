/*
�˳������stm32f4���ڰ�˫��ʹ��
	�� USART1��USART2����Ϊ��˫������USART2����USART1����1��ʼ���յ������ݼ�һ�����Է�
	�� ���ߣ�PA9 - PD5
	` debug�۲�res1��res2�������
*/

#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "beep.h"
#include "key.h"

int main(void)
{ 
	u16 times=0;  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//����ϵͳ�ж����ȼ�����2
	delay_init(168);		//��ʱ��ʼ�� 
	LED_Init();		  		
	USART1_Half_Configuration();	//����1����Ϊ��˫��
	USART2_Half_Configuration();	//����2����Ϊ��˫��
	
	sendOnly(USART2);						//USART2ֻд
	readOnly(USART1);						//USART1ֻ��
	USART_SendData(USART2,1);		//USART2�ȷ���USART1
	while(1)
	{
		times++;
		if(times%30==0)LED0=!LED0;//��˸LED,��ʾϵͳ��������.
		delay_ms(10);   
	}
}

