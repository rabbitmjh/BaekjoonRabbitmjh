#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<p, string> pp;

int n;
vector <pp> v;

int main() {
	FIO;
	cin >> n;
	for (int i = 0;i < n;i++) {
		string s;cin >> s;
		int tmp = 0;
		for (int i = 0;i < s.size();i++) {
			if (s[i] - '0' <= 9)
				tmp += s[i] - '0';
		}
		v.push_back({ {s.size(), tmp}, s});
	}

	sort(v.begin(), v.end());
	for (int i = 0;i < n;i++)
		cout << v[i].second << "\n";

	return 0;
}