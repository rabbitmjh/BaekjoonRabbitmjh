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
typedef pair<int, p> pp;

int arr[105], shu[105], ans[105];

int main() {
	int n, cnt = 3;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	for (int i = 1; i <= n; i++)
		cin >> shu[i];

	while (cnt--) {
		for (int i = 1; i <= n; i++)
			ans[i] = shu[arr[i]];
		for (int i = 1; i <= n; i++)
			shu[i] = ans[i];
	}

	for (int i = 1; i <= n; i++)
		printf("%d\n", ans[i]);


	return 0;
}