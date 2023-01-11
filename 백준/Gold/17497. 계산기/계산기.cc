#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<ll, ll> p;
typedef pair<int, p> pp;

ll n, cmp, cnt;
vector <char> v;

int main() {
	FIO;
	cin >> n;

	while (n != 2) {
		if (n % 2 == 1) {
			n *= 2;
			v.push_back('/');
		}
		else if ((n / 2) % 2 == 1) {
			n -= 2;
			v.push_back('+');
		}
		else {
			n /= 2;
			v.push_back('*');
		}
		if (n == 1) {
			n *= 2;
			v.push_back('/');
		}
		if (n == 0)
			break;
	}
	v.push_back('+');

	if (v.size() > 99)cout << -1;
	else {
		cout << v.size() << "\n";
		for (int i = v.size() - 1;i > -1;i--)
			cout << "[" << v[i] << "] ";
	}
	return 0;
}
