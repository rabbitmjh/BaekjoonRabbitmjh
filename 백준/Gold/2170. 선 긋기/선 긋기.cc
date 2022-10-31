#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, ans, l = -INT32_MAX, r = -INT32_MAX;
vector <p> v;

int main() {
	FIO;
	cin >> n;

	for (int i = 0;i < n;i++) {
		int x, y;cin >> x >> y;
		v.push_back({ x,y });
	}
	sort(v.begin(), v.end());

	for (int i = 0;i < v.size();i++) {
		if (r < v[i].first) {//공백이 있을때==현재 끝점이 새로 생긴 줄보다 작음
			ans += r - l;

			l = v[i].first;
			r = v[i].second;
		}
		else//현재 끝점이 새로 생긴 줄보다 같거나 오른쪽임
			r = max(r, v[i].second);
	}

	ans += r - l;
	cout << ans;
	return 0;
}