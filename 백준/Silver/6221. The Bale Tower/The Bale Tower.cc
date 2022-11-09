#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, ans;
vector <p> v;

void go(int num, int cnt) {
	if (num == v.size())return;

	int x = v[num].first, y = v[num].second;
	ans = max(ans, cnt);

	num++;
	if (num == v.size())return;
	for (num; num < v.size(); num++) {
		int nextX = v[num].first, nextY = v[num].second;
		if (x > nextX && y > nextY) {
			go(num, cnt + 1);
		}
	}
	return;
}


int main() {
	FIO;
	cin >> n;
	while (n--) {
		int a, b; cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end(), greater<>());

	for (int i = 0; i < v.size(); i++) {
		go(i, 1);
	}

	cout << ans;

	return 0;
}