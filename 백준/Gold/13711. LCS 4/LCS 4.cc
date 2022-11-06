#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, a[100005], b[100005], ans[100005], cnt;
vector <int> v;

int main() {
	FIO;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		cin >> b[i];
	for (int i = 1; i <= n; i++)
		ans[b[i]] = i;

	for (int i = 1; i <= n; i++)
		a[i] = ans[a[i]];

	v.push_back(-1e9);
	for (int i = 1; i <= n; i++) {
		if (v.back() < a[i]) {
			v.push_back(a[i]);
			cnt++;
		}
		else {
			auto it = lower_bound(v.begin(), v.end(), a[i]);
			*it = a[i];
		}
	}
	cout << cnt;

	return 0;
}