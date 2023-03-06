/************************************************************
           File : main.cpp
           Author : Robin Thomas
					 Version : 1.0
					 Date : 27.02.2023
					 Description : LED control application				               
************************************************************/
#include "Led.h"       // Led class header        

int main(void)
{
	pinmap_t LED_Pin = {GPIOB,GPIO_PIN_0};
	
	HAL_Init();
	
	static TimerGen LedBlink(LED_Pin);
	LedBlink.Led_Ctrl();

	while(1)
	{
		LedBlink.Led_Ctrl();
	}
}	


/***********System tick timer definition********************/
extern "C" void SysTick_Handler(void)
{
   HAL_IncTick();
}