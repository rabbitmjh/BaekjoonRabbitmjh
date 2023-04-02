#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

ll n, m, cycle;
vector <ll> v;

int main() {
	FIO;
	cin >> n >> m;
	for (int i = 0; i < 20000; i++) {
		v.push_back(n);
		if (n % 2 == 0)
			n = (n / 2) ^ 6;
		else
			n = (n * 2) ^ 6;
		auto idx = find(v.begin(), v.end(), n);
		int vidx = idx - v.begin();
		if (idx == v.end())continue;
		else {
			cycle = vidx;
		}
	}
	
	if (v.size() > m)
		cout << v[m];
	else
		cout << v[(m - v.size()) % (v.size() - cycle) + cycle];

	return 0;
}