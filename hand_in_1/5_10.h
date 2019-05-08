#ifndef H_5_10_H
#define H_5_10_H

void guassian_elimination(double **A, double *b, double *u, int n);
int which_row_max(double** A, int k, int n);
void make_P(double** P, int k, int max, int n);
void duplicate(double** A, double** B, int n);
void duplicate(double* a, double* b, int n);
void Multiply(double **res, double **A, double **B, int ARows, int ACols, int BRows, int BCols);
void Multiply(double *res, double **A, double *B, int ARows, int ACols, int BRows);

#endif
