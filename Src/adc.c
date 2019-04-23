#include "adc.h"

float get_temperature(ADC_HandleTypeDef* hadc){
	uint32_t value = HAL_ADC_GetValue(hadc);
	return value;
}
