#include "5_4.h"
#include <cassert>
#include <cmath>

double calc_std(double a[], int length)
{
	assert(length > 0);
	double std = 0;
	double x_bar = calc_mean(a, length);
	if (length > 1)
	{
		for (int i = 0; i < length; i++)
		{
			std += pow((a[i]-x_bar), 2);
		}
		std /= ((double)(length-1));
		std = pow(std, 0.5);
	}
	return std;
}

double calc_mean(double a[], int length)
{
	assert (length > 0);
	double x_bar = 0;
	for (int i = 0; i < length; i++)
	{
		x_bar += a[i];
	}	
	return x_bar / ((double)(length));
}