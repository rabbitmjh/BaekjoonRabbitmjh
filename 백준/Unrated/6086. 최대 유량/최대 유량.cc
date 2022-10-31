#include <iostream>
#include <functional>
#include <utility>
#include <algorithm>
#include <string>
#include <string.h>
#include <cmath>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;
int f[52][52];
int c[52][52];
vector <vector<int>>v;
int n, q, u, w, s, e, ans;
char o, r;
int ctoi(char ch) {//대소문자 구별
	if ('A' <= ch && ch <= 'Z') return ch - 'A';
	else return ch - 'a' + 26;
}
int main() {
	cin >> n;
	v.resize(53);
	//역방향 간선들 추가해줘야함&역방향 간선의 용량도 저장
	for (int i = 0; i < n; i++) {
		scanf(" %c %c %d", &o, &r, &q);
		u = ctoi(o); w = ctoi(r);
		v[u].push_back(w);
		v[w].push_back(u);
		c[u][w] = c[w][u] += q;
	}
	s = ctoi('A'); e = ctoi('Z');
	//증가경로를 반복해서 찾아줌
	while (1) {
		bool findpath = false;
		queue <int> q;
		int path[52] = { 0 };
		bool chk[52] = { 0 };
		q.push(s);
		path[s] = -1;
		chk[s] = 1;
		while (!q.empty()) {
			int cur = q.front();
			chk[cur] = 1;
			q.pop();
			if (cur == e) {
				findpath = true;
				break;
			}
			for (int i = 0; i < v[cur].size(); i++) {
				int next = v[cur][i];
				if (chk[next] == 0 && c[cur][next] - f[cur][next] > 0) {
					chk[next] = 1;
					path[next] = cur;
					q.push(next);
					if (next == e) {
						findpath = true;
						break;
					}
				}
			}
		}
		if (findpath == false) break;
		//경로를 탐색하면서 차단간선을 찾음
		int pos = e; int F = 1001;
		while (path[pos] != -1) {
			int prev = path[pos];
			F = min(F, c[prev][pos] - f[prev][pos]);
			pos = prev;
		}
		//차단간선값을 업데이트 시켜줌
		pos = e;
		while (path[pos] != -1) {
			int prev = path[pos];
			f[prev][pos] += F; f[pos][prev] -= F;
			pos = prev;
		}
		ans += F;
	}
	cout << ans;
	return 0;
}
