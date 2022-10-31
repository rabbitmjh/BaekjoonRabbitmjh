#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, s, cnt, vis[1000005];
vector <int> v, f, ans;

void bfs(int num) {
	queue <p> q;
	q.push({ num,f[num] });

	while (!q.empty()) {
		int now = q.front().first;
		int fuel = q.front().second;
		q.pop();
		if (vis[now])
			continue;

		vis[now] = 1;
		ans.push_back(now);

		int right = now + 1, left = now - 1;
		while (right <= n) {
			if (v[now] + fuel >= v[right] && !vis[right])
				q.push({ right,f[right] });
			else if(v[now] + fuel < v[right])
				break;
			right++;
		}
		while (left > 0) {
			if (v[left] + fuel >= v[now] && !vis[left])
				q.push({ left,f[left] });
			else if (v[left] + fuel < v[now])
				break;
			left--;
		}
	}
}


int main() {
	FIO;
	cin >> n >> s;
	v.push_back(0);
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		v.push_back(a);
	}
	f.push_back(0);
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		f.push_back(a);
	}

	bfs(s);
	sort(ans.begin(), ans.end());

	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	
	return 0;
}