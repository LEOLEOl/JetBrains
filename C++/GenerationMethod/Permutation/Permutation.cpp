#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std;

void printX(int* x, int n)
{
    for (int i = 1; i <= n; ++i) printf("%d ", x[i]);
}

void printData(int* data, int* x, int n)
{
    for (int i = 1; i <= n; ++i) printf("%d ", data[x[i]]);
}

void printData(char* data, int n)
{
    for (int i = 1; i <= n; ++i) printf("%c ", data[i]);
}

void printData(int* data, int n)
{
    for (int i = 1; i <= n; ++i) printf("%d ", data[i]);
}

void reverse(int* x, int p1, int p2) // p1 < p2
{
    while (p1 < p2) {
        swap(x[p1], x[p2]);
        p1++;
        p2--;
    }
}

int* nextPermutation(int* x, int n)
{
    int i, k;

    i = n - 1;
    while (i > 0 & x[i] > x[i + 1]) --i;
    if (i > 0) { // Chưa gặp phải hoán vị cuối cùng
        k = n;// x[k] là phần từ cuối dãy
        while (x[k] < x[i]) --k; // Lùi dần k để tìm được x[k] đầu tiên lớn hơn x[i]
        swap(x[k], x[i]); // đổi chỗ x[k] và x[i]
        reverse(x, i + 1, n);// Lât ngược đoạn cuối
    }
    else return NULL;

    return x;
}

char* getNextPermutation(char* data, int* x, int n)
{
    char* ret = NULL;
    x = nextPermutation(x, n);
    if (x != NULL) {
        ret = new char[n + 1];
        for (int i = 1; i <= n; ++i) ret[i] = data[x[i]];
    }
    return ret;
}

int* getNextPermutation(int* data, int* x, int n)
{
    int* ret = NULL;
    x = nextPermutation(x, n);
    if (x != NULL) {
        ret = new int[n + 1];
        for (int i = 1; i <= n; ++i) ret[i] = data[x[i]];
    }
    return ret;
}

void doCharPermutation()
{
    int n;
    cin >> n;
    int* x = new int[n + 1];
    char* data = new char[n + 1];
    for (int i = 1; i <= n; ++i) x[i] = i; // Cau hinh dau tien
    for (int i = 1; i <= n; ++i) data[i] = 65 + i - 1; // Data dau tien
    char* temp = new char[n + 1];
    memcpy(temp + 1, data + 1, n * sizeof(char));

    while (temp != NULL) {
        printData(temp, n);
        cout << endl;
        delete[] temp;
        temp = getNextPermutation(data, x, n);
    }
}

void doIntPermutation(int n)
{
    //int n;
    //cin >> n;
    int* x = new int[n + 1];
    int* data = new int[n + 1];
    for (int i = 1; i <= n; ++i) x[i] = i; // Cau hinh dau tien
    for (int i = 1; i <= n; ++i) data[i] = 65 + i - 1; // Data dau tien
    int* temp = new int[n + 1];

    memcpy(temp + 1, data + 1, n * sizeof(int));

    while (temp != NULL) {
        printData(temp, n);
        cout << endl;
        delete[] temp;
        temp = getNextPermutation(data, x, n);
    }
}

void doMain()
{
    int i, k, n; // Hoán vị có n phần tử
    cin >> n;
    int* x = new int[n + 1];

    for (i = 1; i <= n; ++i) x[i] = i; // Cấu hình khởi tạo
    do {
        printX(x, n); // In ra cấu hình hiện tại
        cout << endl;

        i = n - 1;
        while (i > 0 & x[i] > x[i + 1]) --i;
        if (i > 0) { // Chưa gặp phải hoán vị cuối cùng
            k = n; // x[k] là phần từ cuối dãy
            while (x[k] < x[i]) --k; // Lùi dần k để tìm được x[k] đầu tiên lớn hơn x[i]
            swap(x[k], x[i]); // đổi chỗ x[k] và x[i]
            reverse(x, i + 1, n);// Lât ngược đoạn cuối
        }
    } while (i != 0);
}



int main()
{
    //doMain();
    doIntPermutation(5);
}