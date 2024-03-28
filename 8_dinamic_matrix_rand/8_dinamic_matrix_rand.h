#include <iostream>

struct Matrix
{
    // Число строк
    int rows;
    // Число столбцов
    int cols;
    // Содержимое матрицы (две звёздочки -- двумерный массив)
    int** data;

    float det;
    float sum;
    float prod;
    int** inv;
};

void printMatrix(Matrix* m)
{
    int i, j;
    for (i = 0; i < m->rows; i++)
    {
        for (j = 0; j < m->cols; j++)
        {
            printf("%3d ", m->data[i][j]);
        }
        printf("\n");
    }
}

// Очистка матрицы из памяти
void freeMatrix(Matrix* m)
{
    int i;
    for (i = 0; i < m->rows; i++)
    {
        free(m->data[i]);
    }
    free(m->data);
    free(m);
}

Matrix* createMatrix(int rows, int cols)
{
    Matrix* m = (Matrix*)malloc(sizeof(Matrix));
    m->rows = rows; // число строк
    m->cols = cols; // число столбцов
    // Создаём динамический массив.
    // Cначала создаётся массив массивов размером m_rows.
    m->data = (int**)malloc(sizeof(int*) * m->rows);
    printf("sizeof(int **) = %d  sizeof(int*) = %d  sizeof(int) = %d\n", sizeof(int **), sizeof(int*), sizeof(int));
    for (int i = 0; i < m->rows; i++)
    {
        // Для каждой строки матрицы мы создаём отдельный массив размером m_cols
        m->data[i] = (int*)malloc(sizeof(int) * m->cols);
        for (int j = 0; j < m->cols; j++)
        {
           // m->data[i][j] = i + j;
            m->data[i][j] = rand()%100; 
           // m->data[i][j] = RAND_MAX;
          //  m->data[i][j] = time(NULL);
        }
    }

    return m; // Возвращаем объект типа Matrix
}