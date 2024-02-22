#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
using namespace std;

// pi = 4 - 4/3 + 4/5 - 4/7 + ...

int main() {

	printf("pi = %f\n", M_PI);
	printf("pi = %.3f\n", M_PI);
	int n;
	scanf_s("%d",&n);

	// Вычислить пи, используя 
	// ряд Грегори

	//округлять сверху
	//3.14159  ->  3.1416
	//3.1415   ->  3.142
	//3.141    ->  3.14

	printf("%.*f", 12, 3.143452342351561);

	return 0;

}