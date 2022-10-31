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
ll arr[105][10];
ll ans[105];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i < 10; i++)arr[1][i] = 1;
	ans[1] = 9;
	for (int i = 2; i <= 100; i++) {
		ll sum = 0;
		for (int j = 0; j < 10; j++) {
			if (j == 0)arr[i][j] = arr[i - 1][j + 1] % 1000000000;
			else if (j == 9)arr[i][j] = arr[i - 1][j - 1] % 1000000000;
			else arr[i][j] = (arr[i - 1][j + 1] + arr[i - 1][j - 1]) % 1000000000;
			sum += arr[i][j];
		}
		sum %= 1000000000;
		ans[i] = sum;
	}
	
	printf("%d", ans[n]);
	return 0;
}