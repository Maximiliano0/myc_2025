/* Includes ---------*/
#include "main.h"

/* Global variables ----*/
extern TIM_HandleTypeDef hpwm;

/* Main Function ----*/
int main(void)
{
  // Hardware Initialize
  Hw_Init();

  // PWM Start
  HAL_TIM_PWM_Start(&hpwm, TIM_CHANNEL_1);

  // Infinite Loop
  while (1)
  {

	// To Stop PWM
	//HAL_TIM_PWM_Stop(&hpwm, TIM_CHANNEL_1);

	// To Change Dutty Cycle;
	//TIM2->CCR1 = _PWMDutty(70, _PWMPeriod(100));

  }

}
