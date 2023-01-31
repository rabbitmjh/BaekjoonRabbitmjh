#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, m, sum, ans, f = -1;
vector <p> v;

bool cmp(p a, p b) {
	if (a.second == b.second)
		return a.first > b.first;
	else return a.second < b.second;
}

int main() {
	FIO;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		v.push_back({ a,b });
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++) {
		if (ans < m) {
			if (f == v[i].second)
				sum += v[i].second;
			else
				f = sum = v[i].second;
		}
		else
			if (f != v[i].second && sum >= v[i].second)
				f = sum = v[i].second;
		ans += v[i].first;
	}

	if (ans < m)cout << -1;
	else cout << sum;
	return 0;
}