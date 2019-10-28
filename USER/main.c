/*
此程序测试stm32f4串口半双工使用
	· USART1和USART2配置为半双工，从USART2发给USART1数据1开始，收到后将数据加一发给对方
	· 连线：PA9 - PD5
	` debug观察res1和res2交替递增
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
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置系统中断优先级分组2
	delay_init(168);		//延时初始化 
	LED_Init();		  		
	USART1_Half_Configuration();	//串口1配置为半双工
	USART2_Half_Configuration();	//串口2配置为半双工
	
	sendOnly(USART2);						//USART2只写
	readOnly(USART1);						//USART1只读
	USART_SendData(USART2,1);		//USART2先发给USART1
	while(1)
	{
		times++;
		if(times%30==0)LED0=!LED0;//闪烁LED,提示系统正在运行.
		delay_ms(10);   
	}
}

