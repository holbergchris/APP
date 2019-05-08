#ifndef H_5_10_H
#define H_5_10_H

void solve3by3(double **A, double *b, double *u);
int which_row_max(double** A, int k);
void make_P(double** P, int k, int max);
void duplicate(double** A, double** B);
void duplicate(double* a, double* b);
void Multiply(double **res, double **A, double **B, int ARows, int ACols, int BRows, int BCols);
void Multiply(double *res, double **A, double *B, int ARows, int ACols, int BRows);

#endif
