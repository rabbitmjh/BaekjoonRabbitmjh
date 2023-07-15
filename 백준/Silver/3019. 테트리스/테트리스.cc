#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, m, ans, arr[105];

int check(string s) {
	vector <int> v;

	for (int i = 0; i < s.size(); i++)
		v.push_back(s[i] - '0');

	int cnt = 0;
	for (int i = 0; i <= n - s.size(); i++) {
		bool flag = true;
		for (int j = 1; j < s.size(); j++) {
			if (v[j] - v[j - 1] != arr[i + j] - arr[i + j - 1]) {
				flag = false;
				break;
			}
		}
		if (flag)
			cnt++;
	}
	return cnt;
}

int main() {
	FIO;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	if (m == 1) {
		ans += check("0");
		ans += check("0000");
	}
	else if (m == 2)
		ans += check("00");
	else if (m == 3) {
		ans += check("001");
		ans += check("10");
	}
	else if (m == 4) {
		ans += check("100");
		ans += check("01");
	}
	else if (m == 5) {
		ans += check("000");
		ans += check("01");
		ans += check("10");
		ans += check("101");
	}
	else if (m == 6) {
		ans += check("000");
		ans += check("20");
		ans += check("011");
		ans += check("00");
	}
	else {
		ans += check("000");
		ans += check("00");
		ans += check("110");
		ans += check("02");
	}
	cout << ans;
	return 0;
}