#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<ll, ll> p;
typedef pair<int, p> pp;

int n, m, mm, arr[105][1000005], w[105], v[105], bag[105], ans = 1;
p a, b;

int main() {
	FIO;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> w[i] >> v[i];

	for (int i = 1; i <= m; i++) {
		cin >> bag[i];
		mm = max(mm, bag[i]);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <=mm; j++) {
			arr[i][j] = max(arr[i][j], arr[i - 1][j]);
			if (j >= w[i])
				arr[i][j] = max(arr[i][j], arr[i - 1][j - w[i]] + v[i]);
		}
	}
	
	for (int i = 2; i <= m; i++) {
		a = { bag[ans],arr[n][bag[ans]] };
		b = { bag[i],arr[n][bag[i]] };
		if (a.second * b.first < a.first * b.second)
			ans = i;
	}
	cout << ans;

	return 0;
}