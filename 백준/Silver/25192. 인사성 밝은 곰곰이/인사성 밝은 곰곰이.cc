#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<double, double> p;
typedef pair<int, p> pp;

int n, ans;
map <string, int> m;

int main() {
	FIO;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		if (s == "ENTER")
			m.clear();
		else 
			if (!m[s]) {
				m[s] = 1;
				ans++;
			}
	}
	cout << ans;
	return 0;
}