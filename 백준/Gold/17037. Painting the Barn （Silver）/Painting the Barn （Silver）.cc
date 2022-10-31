#include <iostream>
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
#include <deque>
using namespace std;
typedef long long ll;
typedef pair<int, int>p;
typedef pair<string, p> pp;

int arr[1005][1005];

int main() {
	int n, k;
	cin >> n >> k;
	int x1, y1, x2, y2;

	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		for (int i = x1; i < x2; i++) {
			arr[i][y1]++;
			arr[i][y2]--;
		}
	}

	int cnt = 0;
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			if (arr[i][j] == k)cnt++;
			arr[i][j + 1] += arr[i][j];
		}
	}
	printf("%d\n", cnt);

	return 0;
}