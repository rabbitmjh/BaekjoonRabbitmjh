#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int>p;
typedef pair<int, p> pp;

int arr[1005];


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int ans = 0;
	int n; cin >> n;
	n = 1000 - n;
	if (n >= 500) {
		ans += n / 500;
		n %= 500;
	}
	if (n >= 100) {
		ans += n / 100;
		n %= 100;
	}
	if (n >= 50) {
		ans += n / 50;
		n %= 50;
	}
	if (n >= 10) {
		ans += n / 10;
		n %= 10;
	}
	if (n >= 5) {
		ans += n / 5;
		n %= 5;
	}
	if (n >= 1) {
		ans += n / 1;
		n %= 1;
	}
	cout << ans;
	return 0;
}