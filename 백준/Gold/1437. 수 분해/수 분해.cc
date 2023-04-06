#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, ans = 1, tmp;

int main() {
	FIO;
	cin >> n;
	if (n <= 3) {
		cout << n;
		return 0;
	}
	tmp = n / 3;

	if (n % 3 == 1) {
		ans = 4;
		tmp--;
	}
	else if (n % 3 == 2)ans = 2;

	while (tmp--) {
		ans *= 3;
		ans %= 10007;
	}
	cout << ans;
	return 0;
}