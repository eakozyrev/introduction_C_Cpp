// использовать scanf вместо scanf_s
//  fopen вместо fopen_s)
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

typedef float my_type;
typedef my_type Matrix_3_3[3][3];

struct matrix_struct {
    Matrix_3_3 data;
    my_type sum = 0;
    my_type prod = 0;
    my_type det;
    Matrix_3_3 inv;
};

void printMatrixStatic(Matrix_3_3 matrix)
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%.3f ", matrix[i][j]);
        }
        printf("\n");
    }
}

struct Rect
{
    int x0;
    int y0;
    int x1:2;
    int y1=1;
};

int cmpfunc(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {

    struct Rect r;
    Rectangle r;
    r.x0 = 5;
    r.y0 = 5;
    r.x1 = 10;
    printf("Rectangle r : {%d, %d, %d, %d}\n", r.x0, r.y0, r.x1, r.y1);

    // ЗАПИСЬ ФАЙЛОВ
    FILE* f_out = fopen("Matrix.txt", "w");
    // Спецификатор доступа
    //  "r" -- только чтение. Если файл не существует, fopen возвращает 0.
    //  "w" -- только запись. Cоздаётся пустой файл.
    //  "a" -- append, добавление. Данные добавляются к концу файла
    if (f_out == 0)
    {
        printf("ERROR: Could not open f_out\n");
        exit(1);
    }
    int i = 0;
    for (i = 0; i < 9; i++)
    {
        fprintf(f_out, "%d\n", i * i);
        // Если вместо переменной FILE* указать stdout,
        // то текст будет выводится в консоль
        FILE* to_console = stdout;
        fprintf(to_console, "Line %d: %d\n", i, i * i);
    }
    fclose(f_out);

    // ЧТЕНИЕ ФАЙЛОВ
    FILE* f_in = fopen("Matrix.txt", "r");
    if (f_in != 0)
    {
        // Файл Matrix.txt точно существует
        printf("Matrix.txt exists\n");
    }
    else
    {
        printf("Matrix.txt does not exist\n");
        exit(1);
    }
 
    matrix_struct matrix;
    while (1)
    {
        int ret_code = 0;
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j) {
                {
                    ret_code = fscanf(f_in, "%f\n", &matrix.data[i][j]);
                    // файл закончился
                    if (ret_code <= 0) break;
                }
            }

        if (ret_code <= 0) break;
    }
    fclose(f_in);

    printMatrixStatic(matrix.data);

    printMatrixStatic(matrix.inv);

    int arr[] = { 3,1,6,3 };

    //qsort(arr, sizeof(arr)/sizeof(arr[0]), sizeof(arr[0]), cmpfunc);
    std::sort(arr, arr + sizeof(arr) / sizeof(arr[0]));
    for (auto i : arr)printf("%d ", i);

    return 0;
}
