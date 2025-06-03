/* Includes ---------*/
#include "main.h"

/* Main Function ----*/
int main(void)
{
  float temp;

  // API Initialization
  API_Init();

  // Infinite Loop
  while (1)
  {
	  temp = API_GetTemperature();
	  if((temp > (_SetPoint+_Hysteresis)) || (temp < (_SetPoint-_Hysteresis))){
		  API_Heater(HON);
	  }
	  else{
		  API_Heater(HOFF);
	  }

  }

  return 0;
}
