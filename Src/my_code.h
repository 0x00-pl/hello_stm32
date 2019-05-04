#pragma once
#include "main.h"
#include <string.h>

uint32_t get_temperature(ADC_HandleTypeDef* hadc);


void loop(ADC_HandleTypeDef* hadc1, UART_HandleTypeDef* huart1);
