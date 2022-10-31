#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int>p;
int a, b;
p arr[45];

int main() {
	int t; cin >> t;
	arr[0].first = 1;
	arr[0].second = 0;
	arr[1].first = 0;
	arr[1].second = 1;
	for (int i = 2; i <= 40; i++) {
		arr[i].first = arr[i - 1].first + arr[i - 2].first;
		arr[i].second = arr[i - 1].second + arr[i - 2].second;
	}
	while (t--) {
		int n;
		scanf("%d", &n);
		printf("%d %d\n", arr[n].first, arr[n].second);
	}

	return 0;
}