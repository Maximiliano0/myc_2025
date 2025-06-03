/* Libraries	*/
#include "gpio.h"

/* GPIO Configuration */
void GPIO_Config(void){

	GPIO_InitTypeDef Heater_Pin_Conf = {0};

	__HAL_RCC_GPIOA_CLK_ENABLE();

	Heater_Pin_Conf.Pin = HEATER_PIN;
	Heater_Pin_Conf.Mode = GPIO_MODE_OUTPUT_PP;
	Heater_Pin_Conf.Pull = GPIO_NOPULL;
	Heater_Pin_Conf.Speed = GPIO_SPEED_FREQ_LOW;

	HAL_GPIO_Init(HEATER_PORT, &Heater_Pin_Conf);

	return;
}

/* GPIO Pin Configuration	*/
void GPIO_Pin_OnOff(Pin_State state, Pin_Type pin){

	if(state == PON) HAL_GPIO_WritePin(pin.port, pin.num, GPIO_PIN_SET);
	else HAL_GPIO_WritePin(pin.port, pin.num, GPIO_PIN_RESET);

	return;
}

