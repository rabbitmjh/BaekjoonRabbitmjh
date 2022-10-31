#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, m, t[305], vis[305], ans, sum;
vector <pp> v;
priority_queue <pp> pq;

int find(int num) {
	if (num == vis[num])
		return num;
	return vis[num] = find(vis[num]);
}

bool merge(int a, int b) {
	a = find(a);b = find(b);
	if (a == b)return false;
	if (t[a] > t[b])swap(a, b);
	vis[b] = a;
	return true;
}

int main() {
	FIO;
	cin >> n;
	for (int i = 1;i <= n;i++) {
		vis[i] = i;
		cin >> t[i];
		ans += t[i];
	}

	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			int tmp;
			cin >> tmp;
			if (i == j) continue;
			v.push_back({ tmp,{i,j} });
		}
	}
	
	sort(v.begin(), v.end());
	sum = ans;
	for (int i = 0;i < v.size();i++) {
		int a = v[i].second.first;
		int b = v[i].second.second;
		int c = v[i].first - max(t[find(a)], t[find(b)]);
		if (c > -1)continue;

		if (find(a) != find(b)) {
			merge(a, b);
			sum += c;
			ans = min(ans, sum);
		}
	}

	cout << ans;

	return 0;
}