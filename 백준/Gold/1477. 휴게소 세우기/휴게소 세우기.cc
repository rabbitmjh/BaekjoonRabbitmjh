#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, m, k, ans, l = 1, r, mid;
vector <int> v;

int main() {
    FIO;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        v.push_back(a);
    }
    v.push_back(0);
    v.push_back(k);
    sort(v.begin(), v.end());

    r = k - 1;

    while (l <= r) {
        mid = (l + r) / 2;
        int tmp = 0;
        for (int i = 1; i < v.size(); i++) {
            int dis = v[i] - v[i - 1];

            tmp += (dis / mid);
            if (dis % mid == 0)
                tmp--;
        }

        if (tmp > m)
            l = mid + 1;
        else
            r = mid - 1;
    }

    cout << l;

    return 0;
}