#include <iostream>
#include <vector>
using namespace std;
#define FIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int n, k, l, r, ans = 2147483647, p[10005], pp[10005], cnt_pp, cnt_p; //pp가 p'이다
vector <int> v;

int main() {
	FIO;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		v.push_back(a);
		p[a]++;
	}

	cnt_p = k;
	while (l < n && r < n) {
		if (cnt_pp < k) {
			if (!pp[v[r]])//처음 들어오는 색깔이면 카운트
				cnt_pp++;
			pp[v[r]]++;
			p[v[r]]--;

			if (!p[v[r]])
				cnt_p--;
			r++;
		}
		else {
			if (!p[v[l]])
				cnt_p++;
			p[v[l]]++;
			pp[v[l]]--;
			if (!pp[v[l]])
				cnt_pp--;
			l++;
		}
		if (cnt_p == k && cnt_pp == k)
			ans = min(ans, r - l);
	}

	if (ans == 2147483647)
		cout << 0 << endl;
	else cout << ans << endl;

	return 0;
}