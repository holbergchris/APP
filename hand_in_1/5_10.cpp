#include "5_10.h"
#include <cmath>
#include <cassert>

int which_row_max(double** A, int k, int n)
{
	int max_idx = k;
	double max_val = fabs(A[k][k]);
		for (int j=k+1; j<n; j++)
		{
			if (fabs(A[j][k])>max_val)
			{
				max_idx = j; max_val = A[j][k];
			}
		}
	return max_idx;
}

void make_P(double** P, int k, int max, int n)
{
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
		{
			if (i == j)
			{
				P[i][j] = 1;
			}
			else
			{
				P[i][j] = 0;
			}
		}
	}
	P[k][k] = 0; P[max][max] = 0;
	P[k][max] = 1; P[max][k] = 1;
}

void duplicate(double** A, double** B, int n)
{
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
		{
			B[i][j] = A[i][j];
		}
	}
}

void duplicate(double* a, double* b, int n)
{
	for (int i=0; i<n; i++)
	{
		b[i] = a[i];
	}
}

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

void guassian_elimination(double **A, double *b, double *u, int n)
{
	double** A_old = new double* [n];
	double** A_new = new double* [n];
	double** P = new double* [n];
	double* b_old = new double [n];
	double* b_new = new double [n];
	for (int i=0; i<n; i++)
	{
		A_old[i] = new double [n];
		A_new[i] = new double [n];
		P[i] = new double [n];
		for (int j=0; j<n; j++)
		{
			A_old[i][j] = A[i][j];
			A_new[i][j] = A[i][j];
		}
		b_old[i] = b[i]; b_new[i] = b[i];
	}
	int max;
	double m;
	
	for (int i=0; i<n-1; i++)
	{
		max = which_row_max(A_old, i, n);
		make_P(P, i, max, n);
		Multiply(A_new, P, A_old, n, n, n, n);
		Multiply(b_new, P, b_old, n, n, n);
		duplicate(A_new, A_old, n);
		duplicate(b_new, b_old, n);

		for (int j=i+1; j<n; j++)
		{
			m = A_old[j][i]/A_old[i][i];
			for (int k=i; k<n; k++)
			{
				A_new[j][k] -= m*A_old[i][k];
			}
			b_new[j] -= m*b_new[i];
		}
		duplicate(A_new, A_old, n);
		duplicate(b_new, b_old, n);
	}

	for (int i=0; i<n; i++)
	{
		u[n-i-1] = b_new[n-i-1];
		if (i > 0)
		{
			for (int j=n-i; j<n; j++)
			{
				u[n-i-1] -= A_new[n-i-1][j]*u[j];
			}
		}
		u[n-i-1] /= A_new[n-i-1][n-i-1];
	}
	
	for (int i=0; i<n; i++)
	{
		delete[] A_old[i];
		delete[] A_new[i];
		delete[] P[i];
	}
	delete[] A_old;
	delete[] A_new;
	delete[] P;
	delete[] b_old;
	delete[] b_new;
}