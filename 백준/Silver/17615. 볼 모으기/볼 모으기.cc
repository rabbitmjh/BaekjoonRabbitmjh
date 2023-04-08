#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, rcnt, bcnt, cnt = 1, ans = 1e9;
string s;

int main() {
	FIO;
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'R')rcnt++;
		else bcnt++;
	}

	if (n < 3 || rcnt == n || bcnt == n) {
		cout << 0;
		return 0;
	}

	char tmp = s[0];
	for (int i = 1; i < n; i++) {
		if (tmp == s[i])
			cnt++;
		else
			break;
	}
	if (tmp == 'R')
		ans = min(rcnt - cnt, bcnt);
	else
		ans = min(bcnt - cnt, rcnt);

	tmp = s[n - 1]; cnt = 1;
	for (int i = n - 2; i > -1; i--) {
		if (tmp == s[i])
			cnt++;
		else
			break;
	}

	if (tmp == 'R')
		ans = min(rcnt - cnt, min(bcnt, ans));
	else
		ans = min(bcnt - cnt, min(rcnt, ans));

	cout << ans;

	return 0;
}