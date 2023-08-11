#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, m, ans;
vector <int> v, v1;

int main() {
	FIO;
	cin >> n >> m;
	for (int i = 0;i < m;i++) {
		int a, b;cin >> a >> b;
		v.push_back(a);
		v1.push_back(b);
	}
	sort(v.begin(), v.end());
	sort(v1.begin(), v1.end());
	while (n > 0) {
		if (n > 6) {
			if (v.front() > v1.front() * 6) {
				ans += v1.front() * 6;
				n -= 6;
			}
			else {
				ans += v.front();
				n -= 6;
			}
		}
		else {
			if (v.front() > v1.front() * n) {
				ans += v1.front() * n;
				n -= n;
			}
			else {
				ans += v.front();
				n -= n;
			}
		}
	}

	cout << ans;

	return 0;
}