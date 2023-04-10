#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

string a, b, chk;
int ans, vis[10];
vector <char> v;
void dfs(int cnt, string tmp) {
	if (cnt == a.size()) {
		if (stoi(tmp) > ans && stoi(tmp) < stoi(b)) {
			ans = stoi(tmp);
			chk = tmp;
		}
		return;
	}
	for (int i = 0;i < v.size();i++) {
		if (vis[v[i] - '0'] > 0) {
			vis[v[i] - '0']--;
			dfs(cnt + 1, tmp + v[i]);
			vis[v[i] - '0']++;
		}
	}
	return;
}

int main() {
	FIO;
	cin >> a >> b;
	for (int i = 0;i < a.size();i++) {
		v.push_back(a[i]);
		vis[a[i] - '0']++;
	}
	sort(v.begin(), v.end(), greater<>());
	if (a.size() > b.size())
		cout << -1;
	else if (a.size() < b.size())
		for (int i = 0;i < v.size();i++)
			cout << v[i];
	else {
		dfs(0, "");
		if (ans < stoi(b) && ans != 0 && chk[0] != '0')
			cout << ans;
		else
			cout << -1;
	}

	return 0;
}