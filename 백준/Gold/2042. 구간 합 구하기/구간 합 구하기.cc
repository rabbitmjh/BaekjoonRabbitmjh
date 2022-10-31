#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
#include <utility>
#include <deque>
#include <string>
#include <limits>
#include <cmath>
#include <cstring>
#include <array>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, m, k, s = 1;
vector <int> v;
ll arr[3000005], num;

void go(int i, ll x) {
	i += s - 1;
	arr[i] = x;
	while (i) {
		i /= 2;
		if (!i)break;
		arr[i] = arr[i * 2] + arr[i * 2 + 1];
	}
}


ll seg(int start, int end, int l, int r, int c) {//c 현재
 	if (l > end || start > r)return 0;
	else if (l <= start && r >= end)return arr[c];
	int mid = (start + end) / 2;
	ll x = seg(start, mid, l, r, c * 2);
	ll y = seg(mid + 1, end, l, r, c * 2 + 1);
	return  x + y;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m >> k;
	while (n > s)
		s <<= 1;

	for (int i = 1; i <= n; i++) {
		cin >> num;
		go(i, num);
	}

	for (int i = 0; i < m + k; i++) {
		ll a, b, c, sum = 0;
		cin >> a >> b >> c;
		if (a == 1)go(b, c);
		else {
			cout << seg(1, s, b, c, 1) << "\n";
		}
	}
	return 0;
}