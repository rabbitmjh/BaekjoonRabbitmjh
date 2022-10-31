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
int arr[15];

int main() {
	arr[1] = 1; arr[2] = 2; arr[3] = 4;
	for (int i = 4; i <= 10; i++)arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
	
	int t; cin >> t;
	while (t--) {
		int n; scanf("%d", &n);
		printf("%d\n", arr[n]);
	}
	return 0;
}