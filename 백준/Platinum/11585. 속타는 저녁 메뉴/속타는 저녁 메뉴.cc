#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, arr[1000005];
char a[2000005], b[2000005];

int gcd(int x, int y) {
    if (!y)return x;
    return gcd(y, x % y);
}

int main() {
    FIO;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[n + i] = a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int tmp = 0;
    for (int i = 1; i < n; i++) {
        while (tmp > 0 && b[i] != b[tmp]) {
            tmp = arr[tmp - 1];
        }
        if (b[i] == b[tmp]) {
            arr[i] = tmp + 1;
            tmp++;
        }
    }

    int cnt = 0;
    tmp = 0;
    for (int i = 0; i < n * 2 - 1; i++) {
        while (tmp > 0 && a[i] != b[tmp]) {
            tmp = arr[tmp - 1];
        }
        if (a[i] == b[tmp]) {
            if (tmp == n - 1) {
                cnt++;
                tmp = arr[tmp];
            }
            else {
                tmp++;
            }
        }
    }

    cout << cnt / gcd(cnt, n) << "/" << n / gcd(cnt, n);

    return 0;
}