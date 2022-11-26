#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, d = 2;
vector <int> v;

int main() {
	FIO;
	cin >> n;
	
	if (n == 1)return 0;
	while (d <= n) {
		if (n % d == 0) {
			v.push_back(d);
			n /= d;
		}
		else d++;
	}
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << "\n";
	return 0;
}