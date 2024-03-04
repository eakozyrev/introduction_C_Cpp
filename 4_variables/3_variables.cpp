#include <iostream>
#include "function.h"
using namespace std;

int A = 10, B{ 10 };

void print(int A) {

    cout << "A = " << A  << endl;
    A = A + 5;
}

int main()
{
    int A = 9;
    cout << "A = " << A << " " << sqrt(A) << " " << fabs(-A) << " " << ::A << "\n";
    {
        int B = 9;
    }
    cout << "B = " << B << " " << ::B << "\n";

    print(A);
    print(A);
    print(F(100-0.00001));

    getchar();

}

float F(float x) {

    auto res = pow(x, 2) - 10 / sqrt(100 - x);
    return res;

}
/*
F(X) = x^2 - 10/sqrt(100-x);
 
4 задача: Решить F(X) = 0 методом Ньютона.
    X* - начальное значение
    while(fabs(Xn-Xn-1) < epsilon){
        Xn = Xn-1 - F(Xn)/F'(Xn);
    }

5 задача: Вычислить интеграл F(X) от 0 до 1 методом трапеций.
*/
