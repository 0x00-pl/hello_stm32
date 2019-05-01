#include "my_code.h"

uint32_t get_temperature(ADC_HandleTypeDef* hadc){
    HAL_ADC_Start(hadc);

    HAL_ADC_PollForConversion(hadc, 100);

    uint32_t value = HAL_ADC_GetValue(hadc);

    HAL_ADC_Stop(hadc);
	return value;
}
