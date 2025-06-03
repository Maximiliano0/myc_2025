/* Libraries	*/
#include "adc.h"

/* Global Variables	*/
ADC_HandleTypeDef hadc;

/* ADC Configuration */
void ADC_Config(void){

	ADC_ChannelConfTypeDef sConfig = {0};
	GPIO_InitTypeDef ADC_Pin_Conf = {0};

	hadc.Instance = ADC1;
	hadc.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV2;
	hadc.Init.Resolution = ADC_RESOLUTION_12B;
	hadc.Init.ScanConvMode = DISABLE;
	hadc.Init.ContinuousConvMode = ENABLE;
	hadc.Init.DiscontinuousConvMode = DISABLE;
	hadc.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
	hadc.Init.ExternalTrigConv = ADC_SOFTWARE_START;
	hadc.Init.DataAlign = ADC_DATAALIGN_RIGHT;
	hadc.Init.NbrOfConversion = 1;
	hadc.Init.DMAContinuousRequests = DISABLE;
	hadc.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
	HAL_ADC_Init(&hadc);

	sConfig.Channel = ADC_CHANNEL_1;
	sConfig.Rank = 1;
	sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
	HAL_ADC_ConfigChannel(&hadc, &sConfig);

	/* ADC Pin Hardware Configuration */
	__HAL_RCC_ADC1_CLK_ENABLE();
    /**ADC1 GPIO Configuration
	  PA1     ------> ADC1_IN1
	 */
	ADC_Pin_Conf.Pin = GPIO_PIN_1;
	ADC_Pin_Conf.Mode = GPIO_MODE_ANALOG;
	ADC_Pin_Conf.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOA, &ADC_Pin_Conf);

	return;
}


/* ADC Read */
float ADC_Read(void){
	uint32_t counts = 0;

	HAL_ADC_Start(&hadc);
	// Poll for 100us
	HAL_ADC_PollForConversion(&hadc, 100);
	// Read Value
	counts = HAL_ADC_GetValue(&hadc);
	// ADC Stop
	HAL_ADC_Stop(&hadc);

	// Voltage
	return(counts * (ADC_RES));

}



