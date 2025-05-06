/* Includes ---------*/
#include "main.h"

/* Global variables ----*/

/* Main Function ----*/
int main(void)
{
  float dutty=0;

  // Hardware Initialize
  Hw_Init();

  // Infinite Loop
  while (1)
  {
	 // Dutty Cycle Change
	 TIM2->CCR1 = _PWMDutty(dutty, _PWMPeriod(1));
	 // Dummy Delay for Test purpose
	 for(uint32_t nop=0; nop < 10000; nop++);
	 dutty = (dutty<100)?	(dutty+10):0;
  }

}
