#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n;
vector <string> v;

int main() {
	FIO;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string c1, c2, c3, c4;
		bool A = false, B = false, C = false;
		int cnt = 1;

		cin >> c1 >> c2 >> c3 >> c4;
		v.push_back(c1);
		v.push_back(c2);
		v.push_back(c3);
		v.push_back(c4);
		sort(v.begin(), v.end());

		int a = v[0][0] - 'a', b = v[1][0] - 'a', c = v[2][0] - 'a', d = v[3][0] - 'a';
		char q = v[0][1], w = v[1][1], e = v[2][1], r = v[3][1];

		if (q == w && w == e) {
			if (c - b == 1 && b - a == 1)
				A = true;
		}
		if (w == e && e == r) {
			if (d - c == 1 && c - b == 1)
				A = true;
		}
		if (q == w && w == r) {
			if (d - b == 1 && b - a == 1)
				A = true;
		}
		if (q == e && e == r) {
			if (d - c == 1 && c - a == 1)
				A = true;
		}

		for (int j = 1; j < 4; j++) {
			if (v[j] == v[j - 1])
				cnt++;
			else {
				if (cnt > 2)A = true;
				cnt = 1;
			}
		}
		if (cnt > 2)A = true;

		if (v[0] == v[1] && v[2] == v[3])
			C = true;

		if (A || B || C)cout << ":)\n";
		else cout << ":(\n";
		v.clear();
	}

	return 0;
}