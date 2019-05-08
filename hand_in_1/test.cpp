#include "5_10.h"
#include <iostream>

int main(int argc, char* argv[])
{
	double* b = new double [3];
	double* u = new double [3];
	double** B = new double* [3];
	for (int i=0; i<3; i++)
	{
		B[i] = new double [3];
	}
	
	u[0] = 1; u[1] = 1; u[2] = 1;
	B[0][0] = 10; B[0][1] = 1; B[0][2] = 2;
	B[1][0] = 2; B[1][1] = 2; B[1][2] = -5;
	B[2][0] = 3; B[2][1] = 3; B[2][2] = 3;
	
	guassian_elimination(B, u, b, 3);
	std::cout << "Top: " << b[0] << ", mid: " << b[1] << ", bot: " << b[2] << "\n";
	for (int i=0; i<3; i++)
	{
		delete[] B[i];
	}
	delete[] b;
	delete[] u;
	
	return 0;
}