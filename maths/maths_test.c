#include <stdio.h>

#include "maths.h"
#include "matrix.h"

void add_ten(double z, double *ret_value) {
	*ret_value = z + 10;
}

int main() {
	printf("matrix_test-0\n");
	matrix_t *m1, *m2, *product;
	matrix_init(&m1, 2, 3, NULL);
	matrix_init(&m2, 3, 2, NULL);
	matrix_set(m1, 0, 0, 1);
	matrix_set(m1, 0, 1, 2);
	matrix_set(m1, 0, 2, 3);
	matrix_set(m1, 1, 0, 4);
	matrix_set(m1, 1, 1, 5);
	matrix_set(m1, 1, 2, 6);
	matrix_set(m2, 0, 0, 7);
	matrix_set(m2, 0, 1, 8);
	matrix_set(m2, 1, 0, 9);
	matrix_set(m2, 1, 1, 10);
	matrix_set(m2, 2, 0, 11);
	matrix_set(m2, 2, 1, 12);
	matrix_product(m1, m2, &product);
	matrix_print(product, 7, 1);
	matrix_elementwise_func_2(m1, add_ten);
	matrix_print(m1, 7, 1);
	printf("matrix_test-1 (%lu)\n", matrix_num_rows(m1));

	matrix_t *mg;
	matrix_init(&mg, 5, 6, NULL);
	matrix_elementwise_func_3(mg, gaussrand);
	matrix_print(mg, 7, 1);

	matrix_t *c;
	matrix_constant_init(&c, 3, 4, 4.0);
	double scalar = 3.50000;
	matrix_product_scalar(c, scalar);
	printf("matrix_product_scalar\n");
	matrix_print(c, 5, 0);

	matrix_t *z;
	matrix_zero_init(&z, 10, 1);
	matrix_set(z, 7, 0, 1.0);
	size_t amr = 0, amc = 0;
	double amv = matrix_argmax(z, &amr, &amc);
	printf("ARGMAX (%lu)(%lu)(%.4f)\n", amr, amc, amv);

	return 0;
}
