#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define FIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, k;
queue <int> q[21];
ll ans;

int main() {
	FIO;
	cin >> n >> k;
	for (int i = 1;i <= n;i++) {
		string s; cin >> s;

		while (!q[s.size()].empty() && i - q[s.size()].front() > k)
			q[s.size()].pop();
		ans += q[s.size()].size();
		q[s.size()].push(i);
	}

	cout << ans;
	return 0;
}