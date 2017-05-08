#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

void printX(int* x, int k)
{
    //printf("{");
    for (int i = 1; i <= k; ++i) printf("%d ", x[i]);
    //printf("}");
}

void doMain()
{
    int n, k, i; // Tap hop co n phan tu, liet ke cac tap con co K phan tu

    cin >> n >> k;
    int* x = new int[k + 1];

    for (i = 1; i <= k; ++i) x[i] = i;// Cau hinh khoi tao
    do {
        printX(x, k); // In ra cau hinh hien tai
        cout << endl;

        // Sinh tiep
        i = k; // Xét từ cuối dãy lên tìm x[i] chưa đạt tới giới hạn trên n - k + i
        while (i > 0 && x[i] == n - k + i) --i;
        if (i > 0) { // Nếu chưa lùi tới 0 có nghĩa là chưa phải cấu hình kết thúc
            ++x[i]; // Tăng x[i] lên 1, đặt các phần từ đứng sau x[i] là giới hạn dưới
            for (int j = i + 1; j <= k; ++j) x[j] = x[j - 1] + 1;
        }
    } while (i != 0); // Lùi đến tận o có nghĩa là tất cả các phần tử đều đã đạt được giới hạn trên.
}

int* nextCombination(int* x, int n, int k)
{
    // Sinh tiep
    int i = k; // Xét từ cuối dãy lên tìm x[i] chưa đạt tới giới hạn trên n - k + i
    while (i > 0 && x[i] == n - k + i) --i;
    if (i > 0) { // Nếu chưa lùi tới 0 có nghĩa là chưa phải cấu hình kết thúc
        ++x[i]; // Tăng x[i] lên 1, đặt các phần từ đứng sau x[i] là giới hạn dưới
        for (int j = i + 1; j <= k; ++j) x[j] = x[j - 1] + 1;
    }
    else return NULL;
    return x;
}

void printData(char* data, int* x, int k)
{
    for (int i = 1; i <= k; ++i) printf("%c ", data[x[i]]);
}

void printData(char* data, int k)
{
    for (int i = 1; i <= k; ++i) printf("%c ", data[i]);
}

void printData(int* data, int k)
{
    for (int i = 1; i <= k; ++i) printf("%d ", data[i]);
}

char* getNextCombination(char* data, int* x, int n, int k)
{
    char* ret = NULL;
    x = nextCombination(x, n, k);
    if (x != NULL) {
        ret = new char[k + 1];
        for (int i = 1; i <= k; ++i) ret[i] = data[x[i]];
    }
    return ret;
}

int* getNextCombination(int* data, int* x, int n, int k)
{
    int* ret = NULL;
    x = nextCombination(x, n, k);
    if (x != NULL) {
        ret = new int[k + 1];
        for (int i = 1; i <= k; ++i) ret[i] = data[x[i]];
    }
    return ret;
}

void doCharCombination() // data là cấu hình hiện tại, x là mảng index hiện tại
{
    int n, k; // Tap hop co n phan tu, liet ke cac tap con co K phan tu

    cin >> n >> k;
    int* x = new int[k + 1];
    char* data = new char[n + 1];
    for (int i = 1; i <= k; ++i) x[i] = i;// Cau hinh khoi tao
    for (int i = 1; i <= n; ++i) data[i] = 65 + i-1;

    char* temp = new char[k + 1];
    memcpy(temp + 1, data + 1, k * sizeof(char));

    while (temp != NULL) {
        printData(temp, k);
        cout << endl;
        delete[] temp;
        temp = getNextCombination(data, x, n, k);
    }
}

void doIntCombination(int n, int k) // data là cấu hình hiện tại, x là mảng index hiện tại
{
    //int n, k; // Tap hop co n phan tu, liet ke cac tap con co K phan tu

    //cin >> n >> k;
    int* x = new int[k + 1];
    int* data = new int[n + 1];
    for (int i = 1; i <= k; ++i) x[i] = i;// Cau hinh khoi tao
    for (int i = 1; i <= n; ++i) data[i] = 65 + i - 1;

    int* temp = new int[k + 1];
    memcpy(temp + 1, data + 1, k * sizeof(int));

    while (temp != NULL) {
        printData(temp, k);
        cout << endl;
        delete[] temp;
        temp = getNextCombination(data, x, n, k);
    }
}


int main ()
{
    doIntCombination(5, 3);
}