#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, k;
queue <int> q;
set <int> s;

int dx[2] = { -1, 1 };

ll bfs() {
	ll ans = 0, happy = 1;
	while (!q.empty()) {
		int size = q.size();
		while (size--) {
			int water = q.front();
			q.pop();
			for (int i = 0; i < 2; i++) {
				int house = water + dx[i];
				if (s.count(house) == 0){
					k--;
					ans += happy;
					s.insert(house);
					q.push(house);
					if (k == 0)
						return ans;
				}
			}
		}
		happy++;
	}
	return ans;
}

int main() {
	FIO;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		q.push(a);
		s.insert(a);
	}
	cout << bfs();
    return 0;
}
