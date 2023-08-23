#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int dp[505][505], cost[505], sum[505];
int t, k;

int go(int x, int y) {
    if (dp[x][y] != 0x3f3f3f3f)
        return dp[x][y];

    if (x == y)
        return dp[x][y] = 0;

    if (x + 1 == y)
        return dp[x][y] = cost[x] + cost[y];

    for (int mid = x; mid < y; ++mid) {
        int left = go(x, mid);
        int right = go(mid + 1, y);
        dp[x][y] = min(dp[x][y], left + right);
    }

    return dp[x][y] += sum[y] - sum[x - 1];
}

int main() {
    FIO;
    cin >> t;

    while (t--) {
        memset(dp, 0x3f, sizeof(dp));
        cin >> k;
        for (int i = 1; i <= k; i++) {
            cin >> cost[i];
            sum[i] = sum[i - 1] + cost[i];
        }
        cout << go(1, k) << "\n";
    }
    return 0;
}