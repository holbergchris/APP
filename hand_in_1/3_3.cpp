#include "3_3.h"
#include <cassert>
#include <cmath>
#include <iostream>
#include <fstream>

int main(int argc, char* argv[])
{
	int n = atoi(argv[1]);
	assert(n > 1);
	double h = 1.0 / ((double)(n));
	double y[n];
	y[0] = 1;
	
	std::ofstream write_output("xy.dat");
	assert(write_output.is_open());
	write_output << 0 << "," << y[0] << "\n";
	
	for (int i=1; i<n; i++)
	{
		y[i] = y[i-1]/(1.0+h);
		write_output << ((double)(i))*h << "," << y[i] << "\n";
	}
	write_output.close();
	
	return 0;
}