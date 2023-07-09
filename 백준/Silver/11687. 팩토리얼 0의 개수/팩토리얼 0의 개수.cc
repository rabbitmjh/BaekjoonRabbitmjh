#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, l, r, mid, ans, cnt;

int main() {
    FIO;
    cin >> n;
    r = n * 5;
    while (l <= r) {
        mid = (l + r) / 2;
        cnt = 0;
        int tmp = mid;
        while (tmp >= 5) {
            cnt += tmp / 5;
            if (cnt > n)
                break;
            tmp /= 5;
        }

        if (cnt < n)
            l = mid + 1;
        else
            r = mid - 1;
    }

    cnt = 0;
    int tmp = l;
    while (tmp >= 5) {
        cnt += tmp / 5;
        tmp /= 5;
    }
    if (cnt == n)
        cout << l;
    else
        cout << -1;

    return 0;
}