#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<ll, ll> p;
typedef pair<int, p> pp;

int n, q, arr[300005];
vector <int> v;

int main() {
	FIO;
	cin >> n >> q;
	v.push_back(-1);
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	arr[1] = v[1];
	for (int i = 2; i <= n; i++)
		arr[i] = arr[i - 1] + v[i];
	
	while (q--) {
		int a, b; cin >> a >> b;
		cout << arr[b] - arr[a - 1] << "\n";
	}
	return 0;
}