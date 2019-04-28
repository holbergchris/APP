#include "3_3.h"
#include <cassert>
#include <iostream>
#include <fstream>

void implicit_Euler(int n)
{
	assert(n > 1);
	double h = 1.0 / ((double)(n));
	double y_next, y_prev = 1.0;
	
	std::ofstream write_output("xy.dat");
	assert(write_output.is_open());
	write_output << 0.0 << "," << y_prev << "\n";
	
	for (int i=1; i<n; i++)
	{
		y_next = y_prev/(1.0+h);
		y_prev = y_next;
		write_output << ((double)(i))*h << "," << y_next << "\n";
	}
	write_output.close();
}