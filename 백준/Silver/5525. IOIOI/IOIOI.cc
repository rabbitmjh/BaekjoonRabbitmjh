#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
int n;

int main() {
	int n, m, ans = 0;
	string s;
	cin >> n >> m >> s;
	for (int i = 0; i < m; i++) {
		if (s[i] != 'I')continue;
		if (s[i + 1] == 'O'&&s[i + 2] == 'I') {
			int chk = 0;
			while (s[i] == 'I'&&s[i + 1] == 'O') {
				i += 2;
				chk++;
				if (s[i] == 'I'&&chk == n) {
					chk--;
					ans++;
				}
			}
		}
	}
	printf("%d", ans);
	return 0;
}
