//
// Created by LEOLEOl on 5/7/2017.
//

#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std;

void printX(char* x, int n)
{
    for (int i = 1; i <= n; ++i) printf("%d", x[i]);
}

int main()
{
    int i, n; // n la size cua so nhi phan
    //cin >> n;
    n = 10;
    char* x = new char[n + 1];

    memset(x + 1, 0, n); // Cau hinh ban dau la 00..0
    do {
        printX(x, n); // In ra cau hinh hien tai
        cout << endl;

        i = n; //x[i] la phan tu cuoi day, lui dan i cho toi khi gap so 0 hoac khi i = 0 thi dung
        while (i > 0 & x[i] == 1) --i;

        if (i > 0) { // Neu chua phai cau hinh 11..1
            x[i] = 1; // Thay x[i] = 1
            memset(x + i + 1, 0, (n - i) * sizeof (x[1])); // Dat x[i+1] = x[i+2] = ... = x[n] = 0
        }
    } while (i != 0); // Het cau hinh
}

