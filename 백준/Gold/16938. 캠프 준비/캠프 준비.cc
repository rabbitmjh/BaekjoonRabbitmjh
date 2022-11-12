#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, l, r, x, ans, arr[20];

int main() {
	FIO;

	cin >> n >> l >> r >> x;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	for (int i = 0; i < (1 << n); i++) {
		int sum = 0, cnt = 0, rmax = 0, lmin = INT_MAX;
		for (int j = 0; j < n; j++) {
			if ((i & (1 << j)) > 0) {
				lmin = min(lmin, arr[j]);
				rmax = max(rmax, arr[j]);

				sum += arr[j];
				cnt++;
			}
		}
		if (cnt > 1 && l <= sum && sum <= r && rmax - lmin >= x)
			ans++;
	}
	cout << ans;
	return 0;
}