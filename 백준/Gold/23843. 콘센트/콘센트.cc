#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, m, idx, ans;
priority_queue <int, vector<int>, greater<int>> pq;
vector <int> v;

int main() {
	FIO;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end(), greater<int>());

	for (int i = 0; i < m; i++) {
		pq.push(v[idx]);
		idx++;
		if (idx == n)
			break;
	}

	for (int i = idx; i < n; i++) {
		int tmp = pq.top() + v[i];
		pq.pop();
		pq.push(tmp);
	}
	
	while (!pq.empty()) {
		ans = max(ans, pq.top());
		pq.pop();
	}

	cout << ans;

	return 0;
}