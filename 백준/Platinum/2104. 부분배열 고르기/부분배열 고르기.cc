#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n;
ll arr[100005], ans;

ll seg(int l, int r) {
	if (l == r) 
		return arr[l] * arr[r];

	int m = (l + r) / 2;
	int lo = m, hi = m + 1;
	
	ll num = max(seg(l, m), seg(m + 1, r));
	ll mn = min(arr[lo], arr[hi]);
	ll sum = arr[lo] + arr[hi];

	num = max(num, (sum * mn));

	while (l < lo || hi < r) {
		if (hi < r && (lo == l || arr[lo - 1] < arr[hi + 1])) {
			hi++;
			mn = min(mn, arr[hi]);
			sum += arr[hi];
		}
		else {
			lo--;
			mn = min(arr[lo], mn);
			sum += arr[lo];
		}
		num = max(num, sum * mn);
	}

	return num;
}

int main() {
	FIO;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	ans = seg(0, n - 1);
	cout << ans;

	return 0;
}