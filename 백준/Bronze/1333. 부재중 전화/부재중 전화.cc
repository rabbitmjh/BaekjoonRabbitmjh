#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, l, d, t, cnt;

int main() {
	FIO;
	cin >> n >> l >> d;
	t = 0;cnt = d;
	for (int i = 1; i <= n;i++) {
		t += l;
		while (t > cnt)
			cnt += d;
		if (t <= cnt && cnt < t + 5) {
			cout << cnt;
			return 0;
		}
		t += 5;
	}
	cout << cnt;

	return 0;
}