#include <stdio.h>
#define MAX 100

//Передает не сам массив (по значению), а только его указатель на первый элемент
void sum_prod(double res[], int array[], const int n) { 
           //(double *res, int *array, int n) {    // 
    printf("adress = 0x%.8X\n", res);
    printf("sizeof(res) = %d ; sizeof(res[0]) = %d \n", sizeof(res), sizeof(res[0]));
    int sum = 0;
    int prod = array[0];
    for (int i = 0; i < n; i++) {
        sum += array[i];
        if(i > 0)prod *= array[i];
    }
    res[0] = sum;
    res[1] = prod;
} // используя оператор индексации


void sum_prod1(double *res, int *array, const int n) {
    printf("adress = 0x%.8X\n", res);
    printf("sizeof(res) = %d ; sizeof(res[0]) = %d \n", sizeof(res), sizeof(*res));
    int sum = 0;
    int prod = *array;
    int* ref = array;
    for (int i = 0; i < n; i++) {
        sum += *ref;
        if (i > 0)prod *= *ref;
        ref++;
    }
    *res++ = sum;
    *res = prod;
} // используя разыменования указателя

int main()
{
    //auto func = [](int a, int b) {return a + b; };
    //printf("Hello World! %d \n", func(5,6));

    int arr1[] = { 1,2,3,9 };
    arr1[0] = 99;
    const int arr2[] = { 2,6,4 };
    //arr2[0] = 99;  // ERROR
    printf("sizeof(arr2) = %d ; sizeof(arr2[0]) = %d \n", sizeof(arr2), sizeof(arr2[0]));
    for (int i = 0; i < sizeof(arr2)/sizeof(arr2[0]); ++i)printf("%d 0x%.8X %d \n", arr2[i], &arr2[i], *(& arr2[i]));
    
    //const int size = 100;
    int array[MAX]; // size];
    int n;
    scanf_s("%d", &n);

    for (int i = 0; i < n; ++i) {

        scanf_s("%d", &array[i]);

    }
    for (int i = 0; i < MAX; ++i)printf("%d ", array[i]);

    printf("\n");
    double sprod[2];
    printf("adress = 0x%.8X\n", sprod);
    printf("sizeof(sprod) = %d ; sizeof(sprod[0]) = %d \n", sizeof(sprod), sizeof(sprod[0]));
    sum_prod(sprod, array, n);
    printf("sum = %f; prod = %f\n", sprod[0], sprod[1]);
    sum_prod1(sprod, array, n);
    printf("sum = %f; prod = %f\n", sprod[0], sprod[1]);
}
