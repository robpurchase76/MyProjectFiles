/************************************************************
           File : Led_Driver.cpp
           Author : Robin Thomas
					 Version : 1.0
					 Date : 27.02.2023
					 Description : GPIO driver for LED			               
************************************************************/

#include "Led.h" 

TimerGen::TimerGen(pinmap_t& LEDPin)
{
	
	__TIM10_CLK_ENABLE();
	
	/* GPIO COnfiguration */
	LedCtlPin.port = LEDPin.port;
	LedCtlPin.port_pin = LEDPin.port_pin;
	
	GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LEDPin.port, LEDPin.port_pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : PB14 */
  GPIO_InitStruct.Pin = LEDPin.port_pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LEDPin.port, &GPIO_InitStruct);
	
	/* Timer configuration*/
	
	//TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  //TIM_MasterConfigTypeDef sMasterConfig = {0};

 
  htim10.Instance = TIM10;
  htim10.Init.Prescaler = 800-1;
  htim10.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim10.Init.Period = 65536-1;
  htim10.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim10.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  HAL_TIM_Base_Init(&htim10);
	
	/* Start the timer */
	HAL_TIM_Base_Start(&htim10);
	
	/* Read the current counter value */
	Current_Count = __HAL_TIM_GET_COUNTER(&htim10);

}

/*************************************************************/

/**************LED_On method**********************************/
/*void Led::Led_On(void)
{
	HAL_GPIO_WritePin(LedCtlPin.port, LedCtlPin.port_pin, GPIO_PIN_SET);
}*/
/*************************************************************/

/**************LED Off method**********************************/
/*void Led::Led_Off(void)
{
	HAL_GPIO_WritePin(LedCtlPin.port, LedCtlPin.port_pin, GPIO_PIN_RESET);
}*/
/*************************************************************/

/**********************LED toggling function**************************/
void TimerGen::Led_Ctrl(void)
{
  if((__HAL_TIM_GET_COUNTER(&htim10) - Current_Count) >= 1000)
	{
		HAL_GPIO_TogglePin(LedCtlPin.port, LedCtlPin.port_pin);
		Current_Count = __HAL_TIM_GET_COUNTER(&htim10);
	}
	
}

/*********************************************************************/

