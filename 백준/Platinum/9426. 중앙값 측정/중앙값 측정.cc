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

int n, m, arr[500005];
ll ans;
queue <int> q;

void update(int start, int end, int a, int num, int cnt) {
	if (start <= a && a <= end) {
		arr[num] += cnt;
		if (start == end)return;
		update(start, (start + end) / 2, a, num * 2, cnt);
		update((start + end) / 2 + 1, end, a, num * 2 + 1, cnt);
	}
}


int seg(int start, int end, int num, int t) {//c 현재
	if (start == end) return start;
	else if (arr[num * 2] >= t)
		return seg(start, (start + end) / 2, num * 2, t);
	else 
		return seg((start + end) / 2 + 1, end, num * 2 + 1, t - arr[num * 2]);
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		q.push(a);
		update(0, 65536, a, 1, 1);
		if (i >= m - 1) {
			ans += seg(0, 65536, 1, (m + 1) / 2);
			update(0, 65536, q.front(), 1, -1);
			q.pop();
		}
	}

	cout << ans;
	return 0;
}