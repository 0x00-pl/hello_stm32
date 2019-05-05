#include "my_code.h"

uint32_t get_temperature_x100(ADC_HandleTypeDef* hadc){
    HAL_ADC_Start(hadc);

    HAL_ADC_PollForConversion(hadc, 100);

    uint32_t sensorData = HAL_ADC_GetValue(hadc);

    HAL_ADC_Stop(hadc);

    //	  float V25 = 1.43f;
    //	  float AVGSLOPE = 4.3f;
    //	  float temperature = ((1.43f * 1000 - sensorData * 0.8) / 4.3f) + 25;
	return (1430000 - (sensorData * 800)) / 43 + 2500;
}


void loop(ADC_HandleTypeDef* hadc1, UART_HandleTypeDef* huart1){
	  HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
	  uint32_t temperature_x100 = get_temperature_x100(hadc1);
	  char buff[1024];
	  sprintf(buff, "temperature: %ld.%02ldC\n", temperature_x100/100, temperature_x100%100);
	  HAL_UART_Transmit(huart1, (uint8_t*)buff, strlen(buff), 1000);
	  HAL_Delay(1000);
}
