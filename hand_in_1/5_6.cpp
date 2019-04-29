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

void Multiply(double *res, double **A, double *B, int ARows, int ACols, int BRows)
{
	assert(ACols == BRows);
	for (int i=0; i<ARows; i++)
	{
		double tmp = 0.0;
		for (int j=0; j<ACols; j++)
		{
			tmp += B[j]*A[i][j];
		}
		res[i] = tmp;
	}
}

void Multiply(double **res, double scalar, double **B, int BRows, int BCols)
{
	for (int i=0; i<BRows; i++)
	{
		for (int j=0; j<BCols; j++)
		{
			res[i][j] = scalar*B[i][j];
		}
	}
}

void Multiply(double **res, double **B, double scalar, int BRows, int BCols)
{
	for (int i=0; i<BRows; i++)
	{
		for (int j=0; j<BCols; j++)
		{
			res[i][j] = scalar*B[i][j];
		}
	}
}