#include<iostream>
#include <cstdlib>
#include <cstring>
#include <stdio.h>

using namespace std;
int n, k, a[10];
bool check = false;
void display(){

    for (int i = 1; i <= k; i++){
        cout << a[i];
    }
    cout << endl;
}

void nextString(){
    int i = k;
    while (a[i]==n&&i>0){  // nếu a[i] = n và i > 0 thì giảm i
        i--;
    }
    if (i == 0) check = true; // nếu i = 0 thì đã đến cấu hình cuối cùng
    else
    {
        a[i]++;     // tăng a[i] lên 1 đơn vị
        for (int j = i + 1; j <= k; j++){
            a[j] = 1;   // đặt tất cả phần tử phía sau a[i] = 1
        }
    }
}

void printData(char* data, int k)
{
    for (int i = 1; i <= k; ++i) printf("%c ", data[i]);
}

void printData(int* data, int k)
{
    for (int i = 1; i <= k; ++i) printf("%d ", data[i]);
}

int* nextRepeatedArrangement(int* x, int n, int k)
{
    int i = k;
    while (i > 0 & x[i] == n) --i;
    if (i > 0) {
        ++x[i];
        for (int j = i+1; j <= k; ++j) x[j] = 1;
    }
    else return NULL;
    return x;
}

int* getNextRepeatedArrangement(int* data, int* x, int n, int k)
{
    int* ret = NULL;
    x = nextRepeatedArrangement(x, n, k);
    if (x != NULL) {
        ret = new int[k+1];
        for (int i = 1; i <= k; ++i) ret[i] = data[x[i]];
    }
    return ret;
}

char* getNextRepeatedArrangement(char* data, int* x, int n, int k)
{
    char* ret = NULL;
    x = nextRepeatedArrangement(x, n, k);
    if (x != NULL) {
        ret = new char[k+1];
        for (int i = 1; i <= k; ++i) ret[i] = data[x[i]];
    }
    return ret;
}

void doIntRepeatedArrangement(int n, int k) // data là cấu hình hiện tại, x là mảng index hiện tại
{
    //int n, k; // Tap hop co n phan tu, liet ke cac tap con co K phan tu

    int* x = new int[k + 1];
    int* data = new int[n + 1];
    for (int i = 1; i <= k; ++i) x[i] = 1;// Cau hinh khoi tao
    for (int i = 1; i <= n; ++i) data[i] = i;

    int* temp = new int[k + 1];
    memcpy(temp + 1, data + 1, k * sizeof(int));

    int c = 0;
    while (temp != NULL) {
        //printData(temp, k);
        printf("%d. ", ++c);
        for (int i = 1; i <= k; ++i) printf("%d ", data[x[i]]);
        cout << endl;
        delete[] temp;
        temp = getNextRepeatedArrangement(data, x, n, k);
    }
}

int main()
{
    doIntRepeatedArrangement(5, 3);
}