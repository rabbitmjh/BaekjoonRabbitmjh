#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

ll n, q, s = 1, arr[1000005];

ll sum(int i) {
	ll ret = 0;
	while (i) {
		ret += arr[i];
		i -= i & -i;
	}
	return ret;
}

void update(int i, ll diff) {
	int idx = i;
	while(idx <= n) {
		arr[idx] += diff;
		idx += idx & -idx;
	}
}

int main() {
	FIO;
	cin >> n >> q;
	for (int i = 0;i < q;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1)
			update(b, c);
		else
			cout << (ll)(sum(c) - sum(b - 1)) << "\n";
	}

	return 0;
}