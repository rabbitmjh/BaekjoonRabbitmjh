#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int t, k, ans;
vector <p> v;

int main() {
	FIO;
	cin >> t;
	while (t--) {
		int h, w, n;
		cin >> h >> w >> n;

		if (n % h == 0)cout << h;
		else cout << n % h;

		if (n % h == 0 && n / h < 10)
			cout << 0;
		else if (n / h + 1 < 10)
			cout << 0;

		if (n % h == 0)
			cout << n / h << "\n";
		else
			cout << n / h + 1 << "\n";
	}

	return 0;
}