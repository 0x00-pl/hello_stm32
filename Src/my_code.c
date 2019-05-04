#include "my_code.h"

uint32_t get_temperature(ADC_HandleTypeDef* hadc){
    HAL_ADC_Start(hadc);

    HAL_ADC_PollForConversion(hadc, 100);

    uint32_t value = HAL_ADC_GetValue(hadc);

    HAL_ADC_Stop(hadc);
	return value;
}


void loop(ADC_HandleTypeDef* hadc1, UART_HandleTypeDef* huart1){
	  HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
	  uint32_t val = get_temperature(hadc1);
	  char buff[1024];
	  sprintf(buff, "hello: %ld\n", val);
	  HAL_UART_Transmit(huart1, (uint8_t*)buff, strlen(buff), 1000);
	  HAL_Delay(1000);
}
