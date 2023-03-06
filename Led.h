/************************************************************
           File : Led.h
           Author : Robin Thomas
					 Version : 1.0
					 Date : 27.02.2023
					 Description : This header file is used to declare the
					               class for LED driver			               
************************************************************/

#ifndef LED_H
#define LED_H

#include "pinconfig.h"

class TimerGen
{
	private:
		pinmap_t LedCtlPin;
	  TIM_HandleTypeDef htim10;
	  uint16_t Current_Count; // To store the present value of the counter
	public:
		TimerGen(pinmap_t& LEDPin);
	  void Led_Ctrl(void);
};
#endif