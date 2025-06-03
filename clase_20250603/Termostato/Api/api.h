#ifndef API_H_
#define API_H_

/*	Libraries	*/
#include "../Drivers/ADC/ntc.h"
#include "../Drivers/GPIO/gpio.h"
#include "stm32f4xx_hal.h"

/* Constants	*/

/* Data Types	*/
typedef enum{
	HON,
	HOFF
}HState;

typedef enum{
	API_OK,
	API_NOK
}API_Error;

/*	Public Function	*/
/* CLK Config	*/
void SystemClock_Config(void);
float API_GetTemperature(void);
void API_Heater(HState state);
API_Error API_Init(void);


#endif /* API_H_ */
