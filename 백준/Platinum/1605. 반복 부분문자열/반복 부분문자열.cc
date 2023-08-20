#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, ans;
string l;

const int MOD = 100003;
const int MAX = 200000;
int pow2[MAX + 1];

int hashing(const char* c, int sz) {
    int ret = 0;
    for (int i = 0; i < sz; i++) {
        ret *= 2;
        ret %= MOD;
        ret += *(c + i);
    }
    return ret % MOD;
}

bool cmp(const char* i, const char* j, int sz) {
    bool flag = true;
    for (int k = 0; k < sz; k++) {
        if (*(i + k) != *(j + k)) {
            flag = false;
            break;
        }
    }
    return flag;
}

int main() {
    FIO;
    cin >> n >> l;

    pow2[0] = 1;
    for (int i = 1; i < n; i++) {
        pow2[i] = pow2[i - 1] * 2 % MOD;
    }

    int lo = 1, hi = n - 1;
    while (lo <= hi) {
        bool found = false;
        vector<int> table[100003];
        int mid = (lo + hi) / 2;
        int h = hashing(&l[0], mid);

        for (int i = 0; i <= n - mid; i++) {
            if (found) break;
            if (i != 0) {
                h = (h - l[i - 1] * pow2[mid - 1] % MOD + MOD) * 2 % MOD;
                h = (h + l[i + mid - 1]) % MOD;
            }
            if (table[h].size() > 0) {
                for (int pos : table[h]) {
                    if (cmp(&l[i], &l[pos], mid)) {
                        found = true;
                        ans = max(ans, mid);
                        break;
                    }
                }
            }
            table[h].push_back(i);
        }
        if (found) lo = mid + 1;
        else hi = mid - 1;
    }

    cout << ans;

    return 0;
}