#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
char dir[256];
int p[1 << 11][1 << 11];
int k, r, c;
void D() {
    for (int i = 0; i < r; ++i)for (int j = 0; j < c; ++j)p[i + r][j] = p[i][j];
    for (int i = 0; i < r; ++i)for (int j = 0; j < c; ++j)p[i][j] = p[2 * r - i - 1][j] ^ 2;
    r *= 2;
}
void U() {
    for (int i = 0; i < r; ++i)for (int j = 0; j < c; ++j)p[2 * r - i - 1][j] = p[i][j] ^ 2;
    r *= 2;
}
void R() {
    for (int i = 0; i < r; ++i)for (int j = 0; j < c; ++j)p[i][j + c] = p[i][j];
    for (int i = 0; i < r; ++i)for (int j = 0; j < c; ++j)p[i][j] = p[i][2 * c - j - 1] ^ 1;
    c *= 2;
}
void L() {
    for (int i = 0; i < r; ++i)for (int j = 0; j < c; ++j)p[i][2 * c - j - 1] = p[i][j] ^ 1;
    c *= 2;
}
int main(int argc, const char* argv[]) {
    cin >> k;
    for (int i = 0; i < 2 * k; ++i)cin >> dir[i];
    cin >> p[0][0];
    r = c = 1;
    for (int i = 2 * k - 1; i >= 0; --i) {
        if (dir[i] == 'D')D();
        if (dir[i] == 'U')U();
        if (dir[i] == 'R')R();
        if (dir[i] == 'L')L();
    }
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cout << p[i][j] << ' ';
        }
        cout << "\n";
    }
    return 0;
}