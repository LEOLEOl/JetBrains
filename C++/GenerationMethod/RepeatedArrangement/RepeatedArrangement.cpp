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

    int c = 0;
    while (x != NULL) {
        printf("%d. ", ++c);
        for (int i = 1; i <= k; ++i) printf("%d ", data[x[i]]);
        cout << endl;
        x = nextRepeatedArrangement(x, n, k);
    }
}

void bruteforce_attack(int type, int sizePass)
{
    int* x = new int[100];
    char* data = new char[100];

    switch (type) {
        case 1: // 01..9

            break;
        case 2: // ab..z

            break;
        case 3: // AB..Z

            break;
        case 4: // ab..z01..9

            break;
        case 5: // AB..Z01..9

            break;
        case 6: // AB..Zab..z

            break;
        case 7:
        default: // AB..Zab..z01..9

            break;
    }

    while (x != NULL) {
        char* s = "";
    }
}



int main()
{
    doIntRepeatedArrangement(5, 3);
}