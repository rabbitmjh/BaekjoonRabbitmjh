#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<string, string> p;
typedef pair<int, p> pp;

int n;

int main() {
	FIO;
	while (cin >> n && n) {
		vector <p> v;
		for (int i = 0;i < n;i++) {
			string s; cin >> s;
			string ss;
			for (int j = 0;j < s.size();j++) {
				ss.push_back(tolower(s[j]));
			}
			v.push_back({ ss,s });
		}

		sort(v.begin(), v.end());
		cout << v.front().second << "\n";
	}

	return 0;
}
