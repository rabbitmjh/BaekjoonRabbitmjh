#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, m, k;
ll ans;
vector <p> v, w;

int main(){
	FIO;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		v.push_back({ b,a });
	}

	sort(v.begin(), v.end(), greater<>());

	for (int i = 0; i < k; i++) {
		ans += v[i].second;
	}
	for (int i = k; i < v.size(); i++) {
		w.push_back({ v[i].second,v[i].first });
	}
	sort(w.begin(), w.end(), greater<>());

	for (int i = 0; i < m; i++)
		ans += w[i].first;

	cout << ans;
	return 0;
}