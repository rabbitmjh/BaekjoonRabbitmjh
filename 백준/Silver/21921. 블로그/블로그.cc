#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define FIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int x, n, sum, ans, cnt = 1;
vector <int> v;

int main() {
	FIO;
	cin >> x >> n;
	for (int i = 0; i < x; i++) {
		int a; cin >> a;
		v.push_back(a);
		if (i < n)
			sum += a;
	}

	ans = sum;
	int l = 0, r = n;
	for (int i = r; i < x; i++) {
		sum -= v[l];
		sum += v[r];
		l++; r++;
		if (ans == sum)cnt++;
		else if (ans < sum) {
			ans = sum;
			cnt = 1;
		}
	}
	if (!ans)cout << "SAD" << endl;
	else {
		cout << ans << "\n";
		cout << cnt << endl;
	}
	return 0;
}