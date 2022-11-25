#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, t, sum;

int main() {
	FIO;
	cin >> n >> t;
	while (t--) {
		int a, b; cin >> a >> b;
		sum += a * b;
	}
	if (sum == n)cout << "Yes";
	else cout << "No";

	return 0;
}