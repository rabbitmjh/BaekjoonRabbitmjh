#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, m, k, arr[30005], dp[3005];
int c[30005], ans[30005];

int find(int st) {
	if (st == arr[st])return st;
	return arr[st] = find(arr[st]);
}

void uni(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)return;
	if (x < y) {
		c[x] += c[y];
		ans[x] += ans[y];
		arr[y] = x;
	}
	else {
		c[y] += c[x];
		ans[y] += ans[x];
		arr[x] = y;
	}
}

int main() {
	FIO;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		arr[i] = i;
		ans[i] = 1;
	}

	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		uni(x, y);
	}

	for (int i = 1; i <= n; i++) {
		if (arr[i] != i)
			continue;
		for (int j = k - 1; j >= ans[i]; j--)
			dp[j] = max(dp[j], dp[j - ans[i]] + c[i]);
	}
	cout << dp[k - 1];

	return 0;
}