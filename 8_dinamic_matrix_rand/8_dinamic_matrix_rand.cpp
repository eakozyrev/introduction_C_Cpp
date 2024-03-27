#include "8_dinamic_matrix_rand.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h> 

using namespace std;

int main() {
	//Seeds the pseudo-random number generator
	srand(time(NULL));
	int rows, cols;
	scanf("%d %d", &rows, &cols);
	Matrix* m = createMatrix(rows, cols);
	printMatrix(m);
	freeMatrix(m);

	return 0;
}

