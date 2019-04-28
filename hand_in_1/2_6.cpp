#include "2_6.h"
#include <cmath>

double newton_Raphson(double initialGuess, double epsilon)
{
	double x_next, x_prev = initialGuess, step = 0;
	int i = 0;
	while ((fabs(step) > epsilon) || (i == 0))
	{
		step = 	(exp(x_prev)+pow(x_prev, 3.0)-5.0)/
				(exp(x_prev)+3.0*pow(x_prev,2.0));
		x_next = x_prev - step;
		x_prev = x_next;
		i++;
	}
	
	return x_next;
}

