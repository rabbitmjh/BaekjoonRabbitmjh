#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, m, ans;
vector <int> vn, vm;

int main() {
	FIO;
	cin >> n >> m;
	while (1) {
		for (int i = 0;i < n;i++) {
			int a;cin >> a;
			vn.push_back(a);
		}
		for (int i = 0;i < m;i++) {
			int a;cin >> a;
			vm.push_back(a);
		}

		int l = 0, r = 0;
		while (l < n && r < m) {
			if (vn[l] == vm[r]) {
				ans++;
				l++;
				r++;
			}
			else if (vn[l] > vm[r])
				r++;
			else
				l++;
		}
		cout << ans << "\n";
		vn.clear();
		vm.clear();
		ans = 0;
		cin >> n >> m;
		if (n==0 && !m)
			break;
	}
	return 0;
}