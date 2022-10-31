#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int t, n, m, cnt, arr[505];
vector <p> v;
vector <pp> v2;
priority_queue <pp> pq;

int find(int num) {
	if (arr[num] < 0) return num;
	return arr[num] = find(arr[num]);
}

void merge(int a, int b) {
	a = find(a); b = find(b);
	if (a == b)return;
	arr[a] += arr[b];
	arr[b] = a;
}

int main() {
	FIO;
	cin >> t;

	while (t--) {
		memset(arr, -1, sizeof(arr));
		v.clear();
		v2.clear();
		cnt = 0;
		cin >> n >> m;

		for (int i = 0; i < m; i++) {
			int a, b; cin >> a >> b;
			v.push_back({ a,b });
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				if (i == j)
					continue;
				int a = pow(v[i].first - v[j].first, 2);
				int b = pow(v[i].second - v[j].second, 2);
				v2.push_back({ a + b,{i,j} });
			}
		}
		sort(v2.begin(), v2.end());

		for (int i = 0; i < v2.size(); i++) {
			int a = v2[i].first;
			int b = v2[i].second.first;
			int c = v2[i].second.second;
			if (find(b) == find(c))
				continue;

			cnt++;
			merge(b, c);
			if (cnt == (m - n)) {
				cout << fixed << setprecision(2) << sqrt(a) << '\n';
				break;
			}
		}
	}

	return 0;
}