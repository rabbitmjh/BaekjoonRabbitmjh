#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, ans;
vector <p> v;
priority_queue <int, vector<int>, greater<int>> pq;

int main() {
	FIO;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		v.push_back({ a, b });
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		int deadLine = v[i].first;
		int cupRamen = v[i].second;

		pq.push(cupRamen);
		if (pq.size() > deadLine)
			pq.pop();
	}

	while (!pq.empty()) {
		ans += pq.top();
		pq.pop();
	}
	cout << ans;

	return 0;
}