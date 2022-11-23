#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int t;

int main() {
	FIO;
	cin >> t;
	while (t--) {
		int a, b, c; cin >> a >> b >> c;
		cout << min(a, min(b, c)) << "\n";
	}
	return 0;
}