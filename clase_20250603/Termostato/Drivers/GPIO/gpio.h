
#ifndef GPIO_GPIO_H_
#define GPIO_GPIO_H_

/* Includes 	*/
#include <stm32f4xx_hal.h>

/* Macros	*/
#define HEATER_PORT  GPIOA
#define HEATER_PIN   GPIO_PIN_0

/* Data Types	*/
typedef enum{
	PON,
	POFF
}Pin_State;

typedef struct{
	uint16_t num;
	GPIO_TypeDef* port;
}Pin_Type;

/* Public Functions	*/
void GPIO_Config(void); // GPIO Configuration
void GPIO_Pin_OnOff(Pin_State, Pin_Type); // GPIO Pin ON/OFF


#endif /* GPIO_GPIO_H_ */
