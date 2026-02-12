#include <stdio.h>

void solve(float a, float b, float c) {
    /*
    the function is solving equation ax + b = c;
    */

    if (0 == a) {
        printf("Attention, the equation is not valid: a = 0, b = %.2f, c = %.2f\n", b, c);
    } else {
        printf("x = %.2f\n", (c - b) / a);
    }

}

int main()
{
    printf("Hello World!\n");

    /*
    char:  1 байт  -128 до 127

    unsigned char: 1 байт 0 до 255

    short: 2 байт –32768 до 32767

    int: 4 байта  −2 147 483 648 до 2 147 483 647

    long: 8 байт -9223372036854775807 до +9 223 372 036 854 775 807

    float: 4 байта  +/- 3.4E-38 до 3.4E+38

    double: 8 байт  +/- 1.7E-308 до 1.7E+308    

    */

    char A = 'd';
    char B = 102;
    long double C = 3e189;

    printf("A = %c, B = %c, C = %.3Lf\n", A,B,C);
    printf("A = %d, B = %d, C = %d\n", A,B,(int)C);

    getchar();

    printf("A = %c, A + 10 = %c\n", A, A + 10);
    getchar();

    int int_value15 = 15, int_value2 = 2; // объявляем две переменные типа int
    float float_value15 = 15, float_value2 = 2; // объявляем две переменные типа float
    //Неявное преобразование типов данных выполняет компилятор С, 
    //явное преобразование данных выполняет сам программист.

    printf("15   / 2   = %d\n", int_value15 / int_value2);        // неявное преобразование: целочисленное деление
    printf("15   / 2   = %.2f\n", (float)int_value15 / float_value2); // неявное: int → float
    printf("15   / 2   = %.2f\n", float_value15 / (float)int_value2);  // неявное: int → float
    printf("15   / 2   = %.2f\n", float_value15 / float_value2);     // оба float, деление с плавающей точкой

    printf("15.0 / 2   = %.2f\n", 15.0 / 2);                   // явное: 15.0 — float
    printf("15   / 2.0 = %.2f\n", 15 / 2.0);                  // явное: 2.0 — float

    printf("(float)int_value15 / int_value2 = %.2f\n",
           (float)int_value15 / int_value2);                 // явное преобразование типа данных

    printf("(float)15 / 2 = %.2f\n",
           (float)15 / 2);                                   // явное приведение типа


    int D = getchar();

    5 > 4 ? printf("yes %d\n", D) : printf("no %d\n",D);

    getchar();

    solve(1, 2, 3);
    solve(0, 2, 3);

    return 0;
}



