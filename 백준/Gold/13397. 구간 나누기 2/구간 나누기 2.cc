#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, m, arr[5005], l, r = 10005;

int main() {
	FIO;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	while (l <= r) {
		int mid = (l + r) / 2;
		int cnt = 1;
		int mx = 0, mn = INT_MAX;
		for (int i = 0; i < n; i++) {
			mx = max(mx, arr[i]);
			mn = min(mn, arr[i]);
			if (mx - mn > mid) {
				mn = arr[i];
				mx = arr[i];
				cnt++;
			}
		}
		if (cnt > m)
			l = mid + 1;
		else
			r = mid - 1;
	}
	cout << l;

	return 0;
}