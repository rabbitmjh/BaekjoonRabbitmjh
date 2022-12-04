#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<ll, ll> p;
typedef pair<int, p> pp;

ll ccw(p a, p b, p c) {
	ll temp = a.first * b.second + b.first * c.second + c.first * a.second;
	temp = temp - a.second * b.first - b.second * c.first - c.second * a.first;
	if (temp > 0)return 1;
	else if (temp < 0) return -1;
	else return 0;
}

bool check(p q, p w, p e, p r) {
	ll a = ccw(q, w, e);
	ll b = ccw(q, w, r);
	ll c = ccw(e, r, q);
	ll d = ccw(e, r, w);

	if (a * b == 0 && c * d == 0) {
		if (q > w)swap(q, w);
		if (e > r)swap(e, r);
		return q <= r && e <= w;
	}
	return a * b <= 0 && c * d <= 0;
}

int main() {
	FIO;
	ll x1, y1, x2, y2, x3, y3, x4, y4;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
	p q = { x1,y1 }, w = { x2,y2 }, e = { x3,y3 }, r = { x4,y4 };

	if (check(q, w, e, r))cout << 1;
	else cout << 0;
	return 0;
}