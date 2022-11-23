#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

double a, d, k, ans, win, lose, t;

int main() {
	FIO;
	cin >> a >> d >> k;

	t = a;
	win = d / 100;
	ans = win * t;
	lose = 1 - win;
	while (win < 1) {
		t += a;
		win += win * (k / 100);
		if (win >= 1) {
			ans += lose * t;
			break;
		}
		ans += lose * win * t;
		lose = lose * (1 - win);
	}

	cout << fixed;
	cout.precision(6);
	cout << ans;
	return 0;
}