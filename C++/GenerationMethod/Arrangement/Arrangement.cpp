//
// Created by LEOLEOl on 5/7/2017.
//

#include <stdio.h>
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

void printX(int* x, int k)
{
    for (int i = 1; i <= k; ++i) printf("%d ", x[i]);
    cout << endl;
}

void Try(int i, int* x, bool* c, int n, int k) // Thử các cách chọn x[i]
{
    for (int j = 1; j <= n; ++j) {
        if (c[j]) { // Chỉ xét những giá trị j còn tự do
            x[i] = j;
            if (i == k) printX(x, k); // Nếu đã chọn được đến x[k] thì chỉ việc in ra kết quả
            else {
                c[j] = false; // Đánh dấu: j đã bị chọn
                Try(i + 1, x, c, n, k); // Thủ tục này chỉ xét những giá trị còn tự do gán cho x[i+1]
                c[j] = true; // Bỏ đánh dấu: j lại là tự do, bởi sắp tới sẽ thử một cách chọn khác của x[i]
            }
        }
    }
}

void doMain()
{
    int n, k; // n la size cua so nhi phan
    cin >> n >> k;
    int* x = new int[n + 1];
    bool* c = new bool[n + 1];

    memset(c + 1, n, true); // Tất cả các số đều chưa bhị chọn
    Try(1, x, c, n, k); // Thử các cách chọn của giá trị x[1]
}


/// Combination
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
/// end Combination

/// Permutation

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

/// End Permutation

/// Arrangement
int* getNextArrangement(int* data, int* x, int n, int k)
{
    int* temp;
    if ((temp = getNextPermutation(data, x, k)) == NULL) {
        reverse(x, 1, k); // Đảo ngược mảng
        return getNextCombination(data, x, n, k);
    }
    else return temp;
}

char* getNextArrangement(char* data, int* x, int n, int k)
{
    char* temp;
    if ((temp = getNextPermutation(data, x, k)) == NULL) {
        reverse(x, 1, k);
        return getNextCombination(data, x, n, k);
    }
    else return temp;
}

void doIntArrangement()
{
    int n, k; // Tap hop co n phan tu, liet ke cac tap con co K phan tu

    cin >> n >> k;
    int* x = new int[k + 1];
    int* data = new int[n + 1];
    for (int i = 1; i <= k; ++i) x[i] = i;// Cau hinh khoi tao
    for (int i = 1; i <= n; ++i) data[i] = i;

    int* temp = new int[k + 1];
    memcpy(temp + 1, data + 1, k * sizeof(int));

    while (temp != NULL) {
        printData(temp, k);
        cout << endl;
        delete[] temp;
        temp = getNextArrangement(data, x, n, k);
    };
}

void doCharArrangement(int n, int k)
{
    //int n, k; // Tap hop co n phan tu, liet ke cac tap con co K phan tu

    //cin >> n >> k;
    int* x = new int[k + 1];
    char* data = new char[n + 1];
    for (int i = 1; i <= k; ++i) x[i] = i;// Cau hinh khoi tao
    for (int i = 1; i <= n; ++i) data[i] = 65 + i-1;

    char* temp = new char[k + 1];
    memcpy(temp + 1, data + 1, k * sizeof(char));

    int c = 0;
    while (temp != NULL) {
        printf("%d. ", ++c);
        printData(temp, k);
        cout << endl;
        delete[] temp;
        temp = getNextArrangement(data, x, n, k);
    };
}

/// End Arrangement

int main()
{
    doCharArrangement(5, 3);
    //doMain();
    // Git Commit CLion 10:00
}
