#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, m, l, r, arr[105], ans, cnt;
vector <p> v;

int main() {
	FIO;
	cin >> n >> m;
	for (int i = 0;i < m;i++) {
		int a, b;cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());

	for (int i = 0;i < m;i++) {
		int x = v[i].first;
		int y = v[i].second;

		if (r >= x) {
			for (int j = r + 1;j <= y;j++)
				arr[j] = cnt;
			r = max(y, r);
		}
		else {
			l = x;
			r = y;
			cnt++;
			for (int j = l;j <= r;j++)
				arr[j] = cnt;
		}
	}

	for (int i = 1;i <= n;i++) {
		if (!arr[i])
			ans++;
	}
	cout << ans + cnt;

	return 0;
}