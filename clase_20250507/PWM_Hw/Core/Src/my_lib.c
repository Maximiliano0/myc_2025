/* Includes ------------------------------*/
#include "my_lib.h"

/* Macros --------------------------------*/

/* Global Variable -----------------------*/
TIM_HandleTypeDef hpwm; // TIM2 Handler Variable --> Software

/* Public Function Definitions ------------*/

/* Hardware Configuration */
uint8_t Hw_Init(void){

	/* HAL Initialization	*/
	HAL_Init(); // --> Init Software

	/* CLK Configuration */
	SystemClock_Config(); // --> Init Hardware

	/* TIM2 Configuration */
	TIM2_Config(); // --> Init Hardware

	/* GPIO Configuration */
	GPIO_Config(); // --> Init Hardware

	return(1);
}


/* CLK Configuration */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  HAL_RCC_OscConfig(&RCC_OscInitStruct);

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0);

  return;
}

/* GPIO Configuration */
void GPIO_Config(void){

	GPIO_InitTypeDef PWM_Pin_Conf = {0};

	/* GPIO Port Hardware Enable */
	// --> Hardware
	__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();

	/* PWM Pin Features Load */
	// --> Software
	PWM_Pin_Conf.Pin = PWM_PIN;
	PWM_Pin_Conf.Mode = GPIO_MODE_AF_PP;
	PWM_Pin_Conf.Pull = GPIO_NOPULL;
	PWM_Pin_Conf.Speed = GPIO_SPEED_FREQ_LOW;
	PWM_Pin_Conf.Alternate = GPIO_AF1_TIM2;

	/* PWM Pin Hardware Configuration */
	// --> Hardware
	HAL_GPIO_Init(PWM_PORT, &PWM_Pin_Conf);

	// PWM CH1 Start
	HAL_TIM_PWM_Start(&hpwm, TIM_CHANNEL_1);

	return;
}

/* TIM2 Configuration */
void TIM2_Config(void){

	TIM_ClockConfigTypeDef CLK_Source = {0};
	TIM_MasterConfigTypeDef sMasterConfig = {0};
	TIM_OC_InitTypeDef PWM_Config = {0};

	/*  TIM Features Load */
	// --> Software
	hpwm.Instance = PWM_TIMER;
	hpwm.Init.Prescaler = PWM_PRESCALER-1;
	hpwm.Init.CounterMode = TIM_COUNTERMODE_UP;
	hpwm.Init.Period = _PWMPeriod(1); // 1 [ms]
	hpwm.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	hpwm.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;

	/* TIM PWM Hardware Configuration */
	// --> Hardware
	HAL_TIM_PWM_Init(&hpwm);

	/* CLK Source Selection */
	CLK_Source.ClockSource = TIM_CLOCKSOURCE_INTERNAL; // --> Software
	HAL_TIM_ConfigClockSource(&hpwm, &CLK_Source); // --> Hardware

	/* PWM Initialize */
	HAL_TIM_PWM_Init(&hpwm); // --> Software

	/* TIM OVF Interrupt Config */
	sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE; // --> Software
	HAL_TIMEx_MasterConfigSynchronization(&hpwm, &sMasterConfig); // --> Hardware

	/* PWM Features Load */
	// --> Software
	PWM_Config.OCMode = TIM_OCMODE_PWM1;
	PWM_Config.Pulse = _PWMDutty(30, _PWMPeriod(1)); // 30%
	PWM_Config.OCPolarity = TIM_OCPOLARITY_HIGH;
	PWM_Config.OCFastMode = TIM_OCFAST_DISABLE;

	/* PWM Hardware Configuration */
	// --> Software
	HAL_TIM_PWM_ConfigChannel(&hpwm, &PWM_Config, TIM_CHANNEL_1);

	// After this call, the GPIO PA0 of PWM CH1 may be configured (not before!!)

	return;
}


/* Private Function Definitions ------------*/
