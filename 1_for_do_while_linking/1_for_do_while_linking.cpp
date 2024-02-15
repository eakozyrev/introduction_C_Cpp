#include <iostream>
#include "math.h"
#include "time.h"
using namespace std;


int main()
{

    double t1 = clock();
    for (short int i = 0; i < 5; ++i) { cout << i << " ";} cout << endl;
    cout << (clock() - t1)/CLOCKS_PER_SEC << 's';
    getchar();
    for (int i = 0; i < 5; i++) cout << i << " "; cout << endl;
    getchar();
    int i = 0;
    cout << i++ << endl;
    cout << ++i << endl;
    getchar();
    for (int i = 0; i < 5; cout << i++ << " ") cout << i << " "; cout << endl;
    getchar();
    for (int i = 0; i < 5; cout << ++i << " ") cout << i << " "; cout << endl;
    getchar();

    for (auto i = 0; true; i++) {

        if (i > 10) {
            cout << i << " ";
            if (11 == i)continue;
            break;
        }
      
    }
    cout << "\n";
    getchar();
    int myNumbers[5] = { 10, 20, 30, 40, 50 };
    for (int i : myNumbers) {
        cout << i << "\n";
    }
    getchar();
    i = 0;
    do {
        cout << i << " ";
        i++;
    } while (sqrt(i) < 20);
}
