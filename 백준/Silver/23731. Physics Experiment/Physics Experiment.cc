#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<string, int> p;
typedef pair<int, p> pp;

string s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s;
	for (int i = s.size() - 1; i > 0; i--) {
		if (s[i] - '0' > 4) {
			for (int j = i; j < s.size(); j++)
				s[j] = '0';
			s[i - 1]++;
		}
	}
	if (s[0] > '4') {
		for (int i = 0; i < s.size(); i++)s[i] = '0';
		cout << 1 << s;
	}
	else cout << s;

	return 0;
}