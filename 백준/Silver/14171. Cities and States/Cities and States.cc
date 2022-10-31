#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

vector <string> v;
map <string, int> m;
string s;
int n, ans;

int main() {
	FIO;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string a, b;
		cin >> a >> b;
		v.push_back(a.substr(0, 2) + b);
		if (m.count(v[i]))
			m[v[i]]++;
		else
			m.insert({ v[i],1 });
	}

	for (int i = 0; i < n; i++) {
		s = v[i].substr(2, 2) + v[i].substr(0, 2);

		if (v[i] == s)
			continue;

		if (m.count(s))
			ans += m[s];
	}

	cout << ans / 2;

	return 0;
}