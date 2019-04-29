#include "5_9.h"
#include "5_6.h"
#include <cassert>
#include <cmath>
#include <iostream>

double det3by3(double **A)
{
	return  A[0][0]*(A[1][1]*A[2][2]-A[1][2]*A[2][1]) -
			A[0][1]*(A[1][0]*A[2][2]-A[1][2]*A[2][0]) +
			A[0][2]*(A[1][0]*A[2][1]-A[1][1]*A[2][0]);
}

int which_row_max(double** A, int k)
{
	int max_idx = k;
	double max_val = fabs(A[k][k]);
		for (int j=k+1; j<3; j++)
		{
			if (fabs(A[j][k])>max_val)
			{
				max_idx = j; max_val = A[j][k];
			}
		}
	return max_idx;
}

void make_P(double** P, int k, int max)
{
	for (int i=0; i<3; i++)
	{
		for (int j=0; j<3; j++)
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

void duplicate(double** A, double** B)
{
	for (int i=0; i<3; i++)
	{
		for (int j=0; j<3; j++)
		{
			B[i][j] = A[i][j];
		}
	}
}

void duplicate(double* a, double* b)
{
	for (int i=0; i<3; i++)
	{
		b[i] = a[i];
	}
}

void solve3by3(double **A, double *b, double *u)
{
	assert(det3by3(A) != 0);
	double** A_old = new double* [3];
	double** A_new = new double* [3];
	double** P = new double* [3];
	double* b_old = new double [3];
	double* b_new = new double [3];
	for (int i=0; i<3; i++)
	{
		A_old[i] = new double [3];
		A_new[i] = new double [3];
		P[i] = new double [3];
		for (int j=0; j<3; j++)
		{
			A_old[i][j] = A[i][j];
			A_new[i][j] = A[i][j];
		}
		b_old[i] = b[i]; b_new[i] = b[i];
	}
	int max;
	double m;
	
	for (int i=0; i<2; i++)
	{
		std::cout << "Iteration: " << i << "\n";
		max = which_row_max(A_old, i);
		make_P(P, i, max);
		Multiply(A_new, P, A_old, 3, 3, 3, 3);
		Multiply(b_new, P, b_old, 3, 3, 3);
		duplicate(A_new, A_old);
		duplicate(b_new, b_old);

		for (int j=i+1; j<3; j++)
		{
			m = A_old[j][i]/A_old[i][i];
			for (int k=i; k<3; k++)
			{
				A_new[j][k] -= m*A_old[i][k];
			}
			b_new[j] -= m*b_new[i];
		}
		duplicate(A_new, A_old);
		duplicate(b_new, b_old);
	}
	
	u[2] = b_new[2]/A_new[2][2];
	u[1] = (b_new[1] - u[2]*A_new[1][2]) / A_new[1][1];
	u[0] = (b_new[0] - u[2]*A_new[0][2] - u[1]*A_new[0][1]) / A_new[0][0];
}