#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

ll ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
	ll temp = x1 * y2 + x2 * y3 + x3 * y1;
	temp = temp - y1 * x2 - y2 * x3 - y3 * x1;
	if (temp > 0)return 1;
	else if (temp < 0) return -1;
	else return 0;
}

int main() {
	FIO;
	ll x1, y1, x2, y2, x3, y3, x4, y4;

	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
	ll a = ccw(x1, y1, x2, y2, x3, y3);
	ll b = ccw(x1, y1, x2, y2, x4, y4);
	ll c = ccw(x3, y3, x4, y4, x1, y1);
	ll d = ccw(x3, y3, x4, y4, x2, y2);
	if (a * b <= 0 && c * d <= 0)cout << 1;
	else cout << 0;

	return 0;
}