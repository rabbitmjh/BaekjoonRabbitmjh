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
int arr[3000005];

void go(int k, int x) {
	int i = k + s - 1;
	arr[i] = x;
	while (i) {
		i /= 2;
		if (!i)break;
		arr[i] = max(arr[i * 2], arr[i * 2 + 1]);
	}
}


int seg(int start, int end, int l, int r, int c) {//c 현재
	if (l > end || start > r)
		return 0;
	else if (l <= start && r >= end)
		return arr[c];

	int mid = (start + end) / 2;
	int x = seg(start, mid, l, r, c * 2);
	int y = seg(mid + 1, end, l, r, c * 2 + 1);
	return  max(x, y);
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	while (n > s)
		s <<= 1;
	
	for (int i = 1; i <= n; i++) {
		cin >> num;
		go(i, num);
	}

	for (int i = m; i <= n - m + 1; i++)
		cout << seg(1, s, i - m + 1, i + m - 1, 1) << " ";

	return 0;
}