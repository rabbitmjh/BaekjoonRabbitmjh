#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int arr[5][5], vis[5][5], dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
vector <string> v;

void dfs(string s, int cnt, int x, int y) {
	if (cnt == 6) {
		for (int i = 0; i < v.size(); i++) {
			if (v[i] == s)
				return;
		}
		v.push_back(s);
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < 5 && 0 <= ny && ny < 5) {
			string ns = s;
			ns.append(to_string(arr[nx][ny]));
			dfs(ns, cnt + 1, nx, ny);
		}
	}
	return;
}

int main() {
	FIO;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> arr[i][j];

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			dfs(to_string(arr[i][j]), 1, i, j);
		}
	}

	cout << v.size();
	return 0;
}