#include "2_6.h"
#include <iostream>
#include <cmath>

int main(int argc, char* argv[])
{
	double x_prev, x_next=0;
	double epsilon=0.01, step=0;
	while (fabs(step)>epsilon))
	{
		step = 	(exp(x_prev)+pow(x_prev, 3.0)-5.0)/
				(exp(x_prev)+3.0*pow(x_prev,2.0));
		x_next = x_prev - step;
		std::cout 	<< "Iteration: " << i << ", x: " 
					<< x_next << "\n";
		x_prev = x_next;
	}
	
	return 0;
}

