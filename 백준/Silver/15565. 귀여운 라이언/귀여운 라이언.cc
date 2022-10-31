#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define FIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int k, n, l, r, ans;
vector <int> v;

int main() {
	FIO;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		if (a == 1)
			v.push_back(i);
	}

	if (v.size() < k) {
		cout << -1;
		return 0;
	}

	int i = 0;
	while (i < k) {
		r = i;
		i++;
	}
	ans = v[r] - v[l] + 1;

	for (r; r < v.size(); r++) {
		ans = min(ans, v[r] - v[l] + 1);
		l++;
	}

	cout << ans << endl;

	return 0;
}