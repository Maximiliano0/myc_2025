#ifndef ADC_ADC_H_
#define ADC_ADC_H_

/* Includes ------------------------------*/
#include <stm32f4xx_hal.h>

/* Macros --------------------------------*/
#define ADC_RES (3.3/4096)

/* Public Functions ----------------------*/
void ADC_Config(void); // ADC Configuration
float ADC_Read(void); // ADC Read Value


#endif /* ADC_ADC_H_ */
