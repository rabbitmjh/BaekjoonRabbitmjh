#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int t, n;
vector <int> v;

int main() {
	FIO;
	cin >> t;
	while (t--) {
		cin >> n;

		for (int i = 0; i < n; i++) {
			int m; cin >> m;
			if (v.empty() || v.back() < m)
				v.push_back(m);
			else {
				int idx = lower_bound(v.begin(), v.end(), m) - v.begin();
				v[idx] = m;
			}
		}

		cout << v.size() << "\n";
		v.clear();
	}

	return 0;
}