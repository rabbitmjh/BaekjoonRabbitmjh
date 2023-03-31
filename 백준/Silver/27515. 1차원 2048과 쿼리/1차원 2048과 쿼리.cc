#include <iostream>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
#include <stack>
#include <utility>
#include <deque>
#include <string>
#include <climits>
#include <cmath>
#include <string>
#include <array>
#include <map>
#include <set>
#include <cstdio>
#include <cstring>
#include <cstring>
#include <cstdlib>
using namespace std;
#define FIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<ll, ll> p;
typedef pair<int, p> pp;

ll n, m, arr[70];


int main() {
	FIO;
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> m;
		int cnt = 0, pm = 0, tmp[70] = { 0 };
		if (m != 0) {
			if (m < 0)
				pm = 1;

			m = abs(m);
			while (m > 1) {
				m /= 2;
				cnt++;
			}

			if (!pm)arr[cnt]++;
			else arr[cnt]--;
		}
		int mx = -1;
		for (int i = 0;i <= 63;i++) {
			tmp[i] += arr[i];
			tmp[i + 1] = tmp[i] / 2;
			if (tmp[i])
				mx = i;
		}

		if (mx > 62)mx = 62;
		if (mx == -1)cout << "0\n";
		else if (mx == 0)cout << "1\n";
		else {
			ll ans = 1;

			while (mx--)
				ans = ans << 1;
			cout << ans << "\n";
		}
	}

	return 0;
}