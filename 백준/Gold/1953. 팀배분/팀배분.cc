#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
#include <utility>
#include <deque>
#include <string>
#include <limits>
#include <cmath>
#include <cstring>
#include <array>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, vis[105];
vector <int> v[105], blue, white;

void dfs(int m, int team) {
	vis[m] = team;
	for (int i = 0; i < v[m].size(); i++) {
		if (vis[v[m][i]])continue;
		dfs(v[m][i], -team);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		for (int j = 0; j < a; j++) {
			int b; cin >> b;
			v[i].push_back(b);
			v[b].push_back(i);
		}
	}

	for (int i = 1; i <= n; i++)
		if (!vis[i]) {
			if (i % 2 == 0)
				dfs(i, 1);
			else
				dfs(i, -1);
		}
	
	for (int i = 1; i <= n; i++) {
		if (vis[i] == 1)blue.push_back(i);
		else white.push_back(i);
	}

	cout << blue.size() << "\n";
	for (int i = 0; i < blue.size(); i++)
		cout << blue[i]<<" ";
	cout << "\n";
	cout << white.size() << "\n";
	for (int i = 0; i < white.size(); i++)
		cout << white[i]<<" ";

	return 0;
}