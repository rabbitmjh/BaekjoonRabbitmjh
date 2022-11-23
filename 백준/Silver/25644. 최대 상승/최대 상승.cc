#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, mn = INT_MAX, mx, ans;

int main() {
	FIO;
	cin >> n;
	while (n--) {
		int a; cin >> a;
		if (mx < a) {
			mx = a;
			if (mn && mx > mn)
				ans = max(ans, mx - mn);
		}
		if (mn > a) {
			mn = a;
			mx = 0;
		}
	}
	cout << ans;
	return 0;
}