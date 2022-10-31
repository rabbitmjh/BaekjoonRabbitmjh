#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, m, ans, x, y;
vector <int> v, v2;

int main() {
	FIO;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		v.push_back(a + b);
		v2.push_back(a - b);
	}
	sort(v.begin(), v.end());
	sort(v2.begin(), v2.end());

	cout << max(abs(v.back() - v.front()), abs(v2.back()- v2.front()));

	return 0;
}
