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

int arr[100005];

int main() {
	int a, b, c, n;
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + n);

	bool check = true;
	if ((arr[n - 2] - arr[0]) == n - 2 && (arr[n - 1] - arr[n - 2]) > 2) {
		printf("2\n");
		check = false;
	}
	else if ((arr[n - 1] - arr[1]) == n - 2 && (arr[1] - arr[0]) > 2) {
		printf("2\n");
		check = false;
	}

	int j = 0, mn = 0, mx = 0;
	for (int i = 0; i < n; i++) {
		if (check == false)break;
		while (j < n - 1 && arr[j + 1] - arr[i] <= n - 1)j++;
		mn = max(mn, j - i + 1);
	}
	if (check == true)printf("%d\n", n - mn);
	mx = max(arr[n - 2] - arr[0], arr[n - 1] - arr[1]) - n + 2;
	printf("%d", mx);
	return 0;
}