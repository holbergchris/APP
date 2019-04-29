#include "5_6.h"
#include <cassert>

void Multiply(double **res, double **A, double **B, int ARows, int ACols, int BRows, int BCols)
{
	assert(ACols == BRows);
	for (int i=0; i<ARows; i++)
	{
		for (int j=0; j<BCols; j++)
		{
			double tmp = 0.0;
			for (int k=0; k<ACols; k++)
			{
				tmp += A[i][k]*B[k][j];
			}
			res[i][j] = tmp;
		}
	}
}

void Multiply(double *res, double *A, double **B, int ACols, int BRows, int BCols)
{
	assert(ACols == BRows);
	for (int i=0; i<BCols; i++)
	{
		double tmp = 0.0;
		for (int j=0; j<ACols; j++)
		{
			tmp += A[j]*B[j][i];
		}
		res[i] = tmp;
	}
}