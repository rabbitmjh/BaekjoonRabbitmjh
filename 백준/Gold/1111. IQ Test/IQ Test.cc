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

int arr[55];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	if (n == 1) {
		cout << "A";
		return 0;
	}
	else if (n == 2) {
		if (arr[0] == arr[1])cout << arr[0];
		else cout << "A";
		return 0;
	}

	int x = arr[0], y = arr[1], z = arr[2], a, b;
	if (y - x == 0)a = 0;
	else a = (z - y) / (y - x);
	b = y - x * a;

	for (int i = 2; i < n; i++) {
		if ((arr[i - 1] != arr[i - 2]) && (a != (arr[i] - arr[i - 1]) / (arr[i - 1] - arr[i - 2]))) {
			cout << "B";
			return 0;
		}
		if (b != arr[i] - arr[i - 1] * a) {
			cout << "B";
			return 0;
		}
	}
	cout << arr[n - 1] * a + b;

	return 0;
}