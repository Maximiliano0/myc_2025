/*	Libraries	*/
#include "ntc.h"

/* Private Functions */

/*	Public Functions	*/
float NTC_Read(void){
	float temperature;
	float voltage, RT;

	// Read ADC
	voltage = ADC_Read();

	// Do Math stuff
	RT = (_Rf * voltage)/(_Vdd - voltage);
	temperature = (_Beta * _T0) / (_Beta + _T0 * log(RT/_RT0));

	// Convert K -> Celsius
	temperature = K2C(temperature);

	return(temperature);
}

