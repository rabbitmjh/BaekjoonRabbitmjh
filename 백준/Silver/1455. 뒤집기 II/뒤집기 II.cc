#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<ll, ll> p;
typedef pair<int, p> pp;

int n, m, arr[105][105], ans;
char c[105][105];

void reverse(int y, int x) {
	for (int i = 0; i <= y; i++)
		for (int j = 0; j <= x; j++)
			arr[i][j] = 1 - arr[i][j];
	return;
}

int main() {
	FIO;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> c[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] = c[i][j] - '0';
	for (int i = n - 1; i > -1; i--)
		for (int j = m - 1; j > -1; j--)
			if (arr[i][j]) {
				ans++;
				reverse(i, j);
			}
	cout << ans;
	return 0;
}