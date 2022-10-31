#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <cstdio>
#include <vector>
using namespace std;

vector<int> getPi(string p) {
	int m = (int)p.size();
	vector<int> pi(m, 0);
	int i = 1, cnt = 0;
	while (i + cnt < m) {
		if (p[i + cnt] == p[cnt]) {
			cnt++;
			pi[i + cnt - 1] = cnt;
		}
		else {
			if (!cnt)i++;
			else {
				i += cnt - pi[cnt - 1];
				cnt = pi[cnt - 1];
			}
		}
	}
	return pi;
}
vector<int> kmp(string s, string p) {
	vector<int> ans;
	auto pi = getPi(p);
	int n = (int)s.size(), m = (int)p.size(), j = 0;
	for (int i = 0; i < n; i++) {
		while (j > 0 && s[i] != p[j])
			j = pi[j - 1];
		if (s[i] == p[j]) {
			if (j == m - 1) {
				ans.push_back(i - m + 1);
				j = pi[j];
			}
			else {
				j++;
			}
		}
	}
	return ans;
}
int main() {
	int n; string s;
	cin >> n >> s;
	vector<int> pi = getPi(s);
	printf("%d", n - pi[n - 1]);

	return 0;
}
