#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

char arr[100005][3];
int dp[100005][3];
int n;

int main() {
    FIO;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }

    for (int i = 1; i <= n; i++) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + (arr[i][0] - '0');
        dp[i][1] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2])) + (arr[i][1] - '0');
        dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]) + (arr[i][2] - '0');
    }

    int mx = max(dp[n][0], max(dp[n][1], dp[n][2]));
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; i++) {
        dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + (arr[i][0] - '0');
        dp[i][1] = min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2])) + (arr[i][1] - '0');
        dp[i][2] = min(dp[i - 1][1], dp[i - 1][2]) + (arr[i][2] - '0');
    }

    int mn = min(dp[n][0], min(dp[n][1], dp[n][2]));

    cout << mx << " " << mn;
    return 0;
}