#pragma once
#define SIDE 4
#include <stdlib.h>
#include <stdio.h>

double** new_matrix()
{
	double **matrix = (double**) malloc(SIDE*sizeof(double*));
	int i, j;

	for (i = 0; i < SIDE; ++i)
	{
		matrix[i] = (double*) malloc(SIDE*sizeof(double));
		for (j = 0; j < SIDE; ++j)
			matrix[i][j] = 0.0;
	}

	return matrix;
}

double** load_matrix(const char *path)
{
	double **matrix = new_matrix();
	int number;
	FILE *inlet = fopen(path, "r");
	int i, j;

	for (j = 0; j < SIDE; ++j)
	{
		for (i = 0; i < SIDE; ++i)
		{
			fscanf(inlet, "%d", &number);
			matrix[j][i] = number;
		}
	}

	fclose(inlet);
	return matrix;
}

void write_matrix(double **matrix)
{
	int i, j;

	for (j = 0; j < SIDE; ++j)
	{
		for (i = 0; i < SIDE; ++i)
		{
			printf("%.3lf\t", matrix[j][i]);
		}
		printf("\n");
	}
	printf("\n");
}

double** transpose(double **matrix)
{
	double** transposed = new_matrix();
	int i, j;

	for (i = 0; i < SIDE; ++i)
		for (j = 0; j < SIDE; ++j)
			transposed[i][j] = matrix[j][i];

	return transposed;
}

double internal_product(double *a, double *b)
{
	double result = 0.0;
	int i;

	for (i = 0; i < SIDE; ++i)
		result += a[i] * b[i];

	return result;
}

double** matrix_product(double **a, double **b)
{
	double **bt = transpose(b);
	double **result = new_matrix();
	int i, j;

	for (i = 0; i < SIDE; ++i)
		for (j = 0; j < SIDE; ++j)
			result[j][i] = internal_product(a[j], bt[i]);

	free(bt);
	return result;
}

double _det_(double **a, int n) {
  double det=0, **temp;
  int p, h, k, i, j;
  temp = new_matrix();
  if(n==1) {
    return a[0][0];
  } else if(n==2) {
    det = (a[0][0]*a[1][1]-a[0][1]*a[1][0]);
    return det;
  } else {
    for(p=0;p<n;p++) {
      h = 0;
      k = 0;
      for(i=1;i<n;i++) {
        for(j=0;j<n;j++) {
          if(j==p) {
            continue;
          }
          temp[h][k] = a[i][j];
          k++;
          if(k==n-1) {
            h++;
            k = 0;
          }
        }
      }
      det = det + a[0][p] * _det_(temp,n-1);
	  det *= (p % 2 == 0)? -1 : 1;
    }
    return det;
  }
}

double determinant(double **m)
{
	return _det_(m, SIDE);
}

#undef SIDE
