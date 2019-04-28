#include "2_6.h"
#include <iostream>
#include <cmath>

int main(int argc, char* argv[])
{
	double x[100];
	double step;
	x[0] = 0;
	for (int i=1; i<100, i++)
	{
		step = 	(exp(x[i-1])+pow(x[i-1], 3.0)-5.0)/
				(exp(x[i-1])+3.0*pow(x[i-1],2.0));
		x[i] = x[i-1] - step;
		std::cout 	<< "Iteration: " << i << ", x: " 
					<< x[i] << "\n";
	}
	
	return 0;
}

