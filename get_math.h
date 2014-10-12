#ifndef	        GET_MATH_H_
# define	GET_MATH_H_

#include "struct.h"

double		get_mobile_mean(int *spot_array, int size);
double		get_exponential_mean(int *spot_array, int size);
double		get_standard_deviation(int *spot_array, int size, double mean);
double		get_variance(int *spot_array, int size, double mean);

#endif		/* GET_MATH_H_ */
