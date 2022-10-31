#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, m, vis[1005][10];
vector <int> v[1005], ans;
bool en = false;

bool go(int day, int last) {
	for (int i = 0;i < v[day].size();i++) {
		int now = v[day][i];
		if (vis[day][i])
			continue;

		if (last != now) {
			if (day == n) {
				ans.push_back(now);
				return true;
			}
			if (go(day + 1, now)) {
				ans.push_back(now);
				return true;
			}
			else {
				vis[day][i] = 1;
			}
		}
	}
	return false;
}

int main() {
	FIO;
	cin >> n;
	for (int i = 1;i <= n;i++) {
		int m;cin >> m;
		for (int j = 0;j < m;j++) {
			int a;cin >> a;
			v[i].push_back(a);
		}
		if (v[i].size() == 1 && v[i - 1].size() == 1 && v[i] == v[i - 1])
			en = true;
	}
	if (en) {//처음에 걸러주기
		cout << -1 << endl;
		return 0;
	}

	go(1, 0);
	if (ans.size() != n) {
		cout << -1 << endl;
		return 0;
	}

	//거꾸로 출력
	for (int i = ans.size() - 1;i > -1;i--)
		cout << ans[i] << "\n";

	return 0;
}