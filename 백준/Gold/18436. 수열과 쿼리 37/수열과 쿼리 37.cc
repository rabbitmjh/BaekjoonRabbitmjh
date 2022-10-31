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

int n, m, s = 1;
vector <p> v;
int arr[100005], num;

void go(int i, int x) {
	int k = i + s - 1;
	if (arr[i] % 2 == 0)
		v[k].first++;//first 짝 second 홀
	else v[k].second++;
	while (k) {
		k /= 2;
		if (!k)break;
		v[k].first = v[k * 2].first + v[k * 2 + 1].first;
		v[k].second = v[k * 2].second + v[k * 2 + 1].second;
	}
}


int evenSeg(int start, int end, int l, int r, int c) {//짝수
 	if (l > end || start > r)return 0;
	else if (l <= start && r >= end)return v[c].first;
	int mid = (start + end) / 2;
	int x = evenSeg(start, mid, l, r, c * 2);
	int y = evenSeg(mid + 1, end, l, r, c * 2 + 1);
	return  x + y;
}

int oddSeg(int start, int end, int l, int r, int c) {//홀수
	if (l > end || start > r)return 0;
	else if (l <= start && r >= end)return v[c].second;
	int mid = (start + end) / 2;
	int x = oddSeg(start, mid, l, r, c * 2);
	int y = oddSeg(mid + 1, end, l, r, c * 2 + 1);
	return  x + y;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n ;
	while (n > s)
		s <<= 1;
	v.resize(s * 2);

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		go(i, arr[i]);
	}


	cin >> m;
	for (int i = 0; i < m; i++) {
		ll a, b, c, sum = 0;
		cin >> a >> b >> c;
		if (a == 1) {
			arr[b] = c;
			v[b + s - 1].first = 0;
			v[b + s - 1].second = 0;
			go(b, c);
		}
		else if (a == 2)
			cout << evenSeg(1, s, b, c, 1) << "\n";
		else
			cout << oddSeg(1, s, b, c, 1) << "\n";

	}
	return 0;
}