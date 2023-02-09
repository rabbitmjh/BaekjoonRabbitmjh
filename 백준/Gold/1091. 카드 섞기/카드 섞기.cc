#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
//typedef pair<int, int> p;
//typedef pair<int, p> pp;

int n, s[50], p[50], tmp[50], ans, origin[50];

int main() {
	FIO;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> p[i];
	for (int i = 0; i < n; i++)
		cin >> s[i];
	for (int i = 0; i < n; i++)
		origin[i] = p[i];

	while (1) {
		bool check = true;

		for (int i = 0; i < n; i++) {
			if (i % 3 != p[i])
				check = false;
		}
		if (check)break;
		ans++;

		for (int i = 0; i < n; i++)
			tmp[s[i]] = p[i];
		for (int i = 0; i < n; i++)
			p[i] = tmp[i];

		int cnt = 0;;
		for (int i = 0; i < n; i++)
			if (origin[i] == p[i])
				cnt++;

		if (cnt == n) {
			cout << -1;
			return 0;
		}
	}
	cout << ans;
	return 0;
}