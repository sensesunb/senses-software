#include <stdio.h>
#include <stdlib.h>
#include "algebra.h"

int main(int argc, char const *argv[]) {
	double **id = load_matrix("data/id.ascii");
	double **pascal = load_matrix("data/pascal.ascii");
	double **square = load_matrix("data/sqrt-2.ascii");

	write_matrix(pascal);
	write_matrix(square);

	write_matrix(matrix_product(pascal, square));
	write_matrix(matrix_product(id, square));
	write_matrix(matrix_product(transpose(square), id));

	printf("%.3lf\n", determinant(id));
	printf("%.3lf\n",
		determinant(matrix_product(pascal, square))/determinant(pascal)/determinant(square));

	return 0;
}
