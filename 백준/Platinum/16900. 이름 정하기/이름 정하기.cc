#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

string s;
ll n;

vector <ll> pi(string str) {
	vector <ll> pii(str.size(), 0);

	for (int i = 1, j = 0; i < str.size(); i++) {
		while (j > 0 && str[i] != str[j])
			j = pii[--j];
		if (str[i] == str[j])
			pii[i] = ++j;
	}
	return pii;
}

int main() {
	FIO;

	cin >> s >> n;

	vector <ll> v = pi(s);
	cout << n * (ll)s.size() - (n - 1) * (ll)v[s.size() - 1];

	return 0;
}
