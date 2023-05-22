#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, sum, ans, tmpL, tmpR, l, r, arr[50005];

int main() {
	FIO;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	r = 1;

	tmpL = arr[0];
	tmpR = sum - tmpL;
	while (l < n) {
		ans = max(ans, min(tmpL, tmpR));
		if (tmpL >= tmpR) {
			tmpL -= arr[l];
			tmpR += arr[l];
			l++;
			continue;
		}

		tmpL += arr[r];
		tmpR -= arr[r];
		r++;
		if (r >= n)
			r = 0;
	}

	cout << ans;

	return 0;
}