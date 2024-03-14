#include <iostream>

void sub(int* ptr, int num) {
    for (auto i{ 0 }; i < num-1; ++i) {
        (*ptr) -= *(ptr + 1);ptr++;  
}}
void sum(int* ptr, int num) {
    for (auto i{ 0 }; i < num - 1; ++i) {
        (*ptr) += *(ptr + 1);ptr++;  
}}
int main()
{
    int n;scanf_s("%d", &n);
    int* arr = (int*)malloc(n*sizeof(int));
    for (auto i{ 0 }; i < n; ++i)scanf_s("%d", &arr[i]); printf("\n");
    printf("sizeof(arr) = %d  sizeof(arr[0]) = %d\n\n", sizeof(arr), sizeof(arr[0]));
    for (auto i{ 0 }; i < n; ++i)printf("%d ", arr[i]); printf("\n");
    void (*func) (int* ptr, int num);
    func = sub;
    func(arr, n);// sizeof(arr) / sizeof(arr[0]));
    for (auto i{ 0 }; i < n; ++i)printf("%d ", arr[i]); printf("\n");
    func = sum;
    func(arr, n);
    for (auto i{ 0 }; i < n; ++i)printf("%d ", arr[i]); printf("\n");

    free(arr);

    return 0;
}
