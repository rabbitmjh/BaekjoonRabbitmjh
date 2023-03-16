#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

string s, s1, s2;
int n, m;

int main() {
	FIO;
	cin >> s;

	bool check = true;
	for (int i = 0;i < s.size();i++) {
		if (s[i] == ':') {
			check = false;
			continue;
		}
		if (check)s1.push_back(s[i]);
		else s2.push_back(s[i]);
	}

	n = stoi(s1);
	m = stoi(s2);

	int cnt = 2;
	while (1) {
		if (n % cnt == 0 && m % cnt == 0) {
			n /= cnt;
			m /= cnt;
		}
		else
			cnt++;
		if (n < cnt || m < cnt)break;
	}
	cout << n << ":" << m;


	return 0;
}