/* Includes ------------------------------*/
#include "stm32f4xx_hal.h"

/* Macros --------------------------------*/
#define PWM_PORT  GPIOA
#define PWM_PIN   GPIO_PIN_0

#define SWITCH_PORT  GPIOA
#define SWITCH_PIN   GPIO_PIN_10
#define SWITCH_OFF   GPIO_PIN_SET
#define SWITCH_ON    GPIO_PIN_RESET

#define PWM_TIMER TIM2
#define CORE_CLK  16000000 // 16 MHz
#define PWM_PRESCALER 1000
#define _PWMPeriod(x)	(((x * (CORE_CLK/1000)) / PWM_PRESCALER)-1)  // Period in [ms] non fractional

#define _PWMDutty(x,y)	((uint32_t) ((((float) x)/100) / y))  // Dutty in percentage



/* Variable Types ------------------------*/

/* Public Function Prototypes ------------*/
uint8_t Hw_Init(void); // Hardware Configuration
void SystemClock_Config(void); // CLK Configuration
void GPIO_Config(void); // GPIO Configuration
void TIM2_Config(void); // TIM2 Configuration
void TIM2_IRQHandler(void); // TIM2 IRQ Routine

/* Private Function Prototypes ------------*/
