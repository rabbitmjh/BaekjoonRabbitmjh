#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<string, int> p;
typedef pair<int, p> pp;

int n, k, x;
vector <int> v;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end(),greater<>());
	cout << v[k - 1];
	
	return 0;
}