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

int n, m, s = 1, num;
vector <int> v;
p arr[300005];

void go(int k, int x) {
	int i = k + s - 1;
	arr[i] = { x,k };
	while (i) {
		i /= 2;
		if (!i)break;
		if (!arr[i * 2].first)
			arr[i] = arr[i * 2 + 1];
		else if (!arr[i * 2 + 1].first)
			arr[i] = arr[i * 2];
		else 
			arr[i] = min(arr[i * 2], arr[i * 2 + 1]);
	}
}


p seg(int start, int end, int l, int r, int c) {//c 현재
	if (l > end || start > r)return{ 0,0 };
	else if (l <= start && r >= end) {
		return arr[c];
	}
	int mid = (start + end) / 2;
	p x = seg(start, mid, l, r, c * 2);
	p y = seg(mid + 1, end, l, r, c * 2 + 1);
	if (!x.first)
		return y;
	else if (!y.first)
		return x;
	else
		return  min(x, y);
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	while (n > s)
		s <<= 1;
	
	for (int i = 1; i <= n; i++) {
		cin >> num;
		go(i, num);
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		ll a, b, c, sum = 0;
		cin >> a >> b >> c;
		if (a == 1)go(b, c);
		else {
			p ans = seg(1, s, b, c, 1);
			cout << ans.second << "\n";
		}
	}
	return 0;
}