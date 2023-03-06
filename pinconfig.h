/************************************************************
           File : pinconfig.h
           Author : Robin Thomas
					 Version : 1.0
					 Date : 27.02.2023
					 Description : This header file is used to create the
					               declarations of GPIO structure 				               
************************************************************/

#ifndef PINCONFIG_H
#define PINCONFIG_H

#include "stm32f4xx_hal.h"

typedef struct
{
	GPIO_TypeDef * port;
	uint16_t port_pin;
}pinmap_t;

#endif