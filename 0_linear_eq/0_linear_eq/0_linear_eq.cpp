#include <iostream>
using namespace std;

int main()
{
    void solve(float, float, float);
    std::cout << "Hello World!\n";

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
    char B{ 102 };
    long double C = 3e189;

    cout << (int)A << " " << B << " " << C << endl;

    getchar();

    cout << "(" << (char)C << ")  " << ((char)C + (100)) << "  " << (char)((char)C + 100) << endl;

    getchar();

    int int_value15 = 15, int_value2 = 2; // объявляем две переменные типа int
    float float_value15 = 15, float_value2 = 2; // объявляем две переменные типа float
    //Неявное преобразование типов данных выполняет компилятор С++, 
    //явное преобразование данных выполняет сам программист.

    cout << "15   / 2   = " << int_value15 / int_value2 << endl  //неявное преобразование типов данных
        << "15   / 2   = " << int_value15 / float_value2 << endl  //неявное преобразование типов данных
        << "15   / 2   = " << float_value15 / int_value2 << endl  //неявное преобразование типов данных
        << "15   / 2   = " << float_value15 / float_value2 << endl; //неявное преобразование типов данных
    cout << "15.0 / 2   = " << 15.0 / 2 << endl  // явное преобразование типа данных, число 15.0 - число с плавающей точкой
        << "15   / 2.0 = " << 15 / 2.0 << endl; // явное преобразование типа данных, число 2.0  - число с плавающей точкой
    cout << "float(int_value15) / int_value2 = " << float(int_value15) / int_value2 << endl; // явное преобразование типа данных
    cout << "static_cast<float>(15) / 2 = " << static_cast<float>(15) / 2 << endl; // унарная операция приведения типа
 
    getchar();

    if (false) {
        cout << false;
    }
    else if (int_value15 == 2)cout << "int_value15 == 2" << endl;
    else if (int_value15 = 2)cout << "int_value15 = " << int_value15 << endl;
    else {
        printf("Hello, World");
    }

    getchar();

    5 > 4 ? printf("yes\n") : printf("no\n");

    getchar();

    solve(1, 2, 3);
    solve(0, 2, 3);

    return 0;
}



void solve(float a, float b, float c) {
    /*
    the function is solving equation ax + b = c;
    */

    if (0 == a)cout << "Attention, the equation is not valid: a = 0" << " b = " << b << " c = " << c;
    else printf("x = %.2f\n",(c - b) / a);

}
