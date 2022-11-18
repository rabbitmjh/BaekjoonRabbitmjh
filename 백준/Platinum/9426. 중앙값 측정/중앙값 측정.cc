#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, k, arr[65540];
ll ans;
vector <int> v;


ll sum(int i) {
	int idx = i;
	ll ans = 0;
	while (idx > 0) {
		ans += arr[idx];
		idx -= idx & -idx;
	}
	return ans;
}

void update(int i, int val) {
	int idx = i;
	while (idx <= 65536) {
		arr[idx] += val;
		idx += idx & -idx;
	}
}


int main() {
	FIO;

	cin >> n >> k;
	v.resize(n + 5);

	for (int i = 1; i <= n; i++) {
		int a; cin >> v[i];

		update(++v[i], 1);

		if (i >= k) {
			int left = 1, right = 65536, cur;

			while (left <= right) {
				int mid = (left + right) / 2;
				if (sum(mid) >= (k + 1) / 2) {//중앙값인지
					right = mid - 1;
					cur = mid;
				}
				else {
					left = mid + 1;
				}
			}
			ans += cur - 1;

			update(v[i - k + 1], -1);
		}
	}

	cout << ans;
	return 0;
}