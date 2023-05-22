#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

ll ans, n, x, y, arr[505];

int main() {
	FIO;
	cin >> n >> x >> y;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	for (int i = 1; i <= n; i++) {
		ll tmp = 0;
		for (int j = i; j <= n; j++) {
			tmp += arr[j];

			ll hp = x * ((y - 1) / tmp + 1);
			ll hpL = 1, hpR, hpM = 0;
			if (i == 1)
				hpL = j + 1;

			for (hpR = hpL; hpR <= n; hpR++) {
				if (hpR == i) {
					hpR = j;
					continue;
				}
				hpM += arr[hpR];

				while (hpM > hp) {
					if (j < hpR)
						ans += (n - hpR + 1);
					else
						ans += n - hpR - (j - i);
					hpM -= arr[hpL];
					hpL++;
					if (hpL == i)
						hpL = j + 1;
				}
			}
		}
	}

	if (!ans)cout << "IMPOSSIBLE";
	else cout << ans;

	return 0;
}