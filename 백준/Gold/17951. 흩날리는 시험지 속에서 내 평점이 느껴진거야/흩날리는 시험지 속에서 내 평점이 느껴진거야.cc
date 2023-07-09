#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, k, arr[100005], l, r, mid;

int main() {
    FIO;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        r += arr[i];
    }
    
    while (l <= r) {
        mid = (l + r) / 2;

        int tmp = 0, score = 0;
        for (int i = 0; i < n; i++) {
            score += arr[i];
            if (score >= mid) {
                tmp++;
                score = 0;
            }
        }
        if (tmp >= k)
            l = mid + 1;
        else
            r = mid - 1;
    }
    cout << r;
    return 0;
}