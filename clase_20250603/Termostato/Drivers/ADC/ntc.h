#ifndef ADC_NTC_H_
#define ADC_NTC_H_

/*	Libraries	*/
#include "math.h"

#include "adc.h"

/* Constants */
#define _Beta 	3300
#define _RT0 	12000
#define _Rf 	12000
#define _T0 	298
#define _Vdd 	3.3

/* Macros */
#define K2C(x) (x-273)

/* Data Types */

/*	Public Functions	*/
float NTC_Read(void);


#endif /* ADC_NTC_H_ */
