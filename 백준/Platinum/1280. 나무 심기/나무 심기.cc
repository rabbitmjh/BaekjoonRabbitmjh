#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, mod = 1000000007;
ll ans = 1;
vector <ll> cnt(200006), dis(200006);


ll cntSum(int i) {
	int idx = i;
	ll sum = 0;
	while (idx > 0) {
		sum += cnt[idx];
		idx -= idx & -idx;
	}
	return sum;
}

ll disSum(int i) {
	int idx = i;
	ll sum = 0;
	while (idx > 0) {
		sum += dis[idx];
		idx -= idx & -idx;
	}
	return sum;
}

void cntUpdate(int i, int val) {
	int idx = i;
	while (idx <= 200005) {
		cnt[idx] += val;
		idx += idx & -idx;
	}
}

void disUpdate(int i, int val) {
	int idx = i;
	while (idx <= 200005) {
		dis[idx] += val;
		idx += idx & -idx;
	}
}


int main() {
	FIO;

	cin >> n;

	for (int i = 0; i < n; ++i) {
		int x; 
		cin >> x;
		x++;

		ll leftTree = cntSum(x);
		ll rightTree = i - leftTree;

		ll leftDist = (leftTree * x - disSum(x)) % mod;
		ll rightDist = (disSum(200005) - disSum(x) - rightTree * x) % mod;

		cntUpdate(x, 1);
		disUpdate(x, x);

		if (i > 0)
			ans = (ans * (leftDist + rightDist) % mod) % mod;
	}

	cout << ans;
	return 0;
}