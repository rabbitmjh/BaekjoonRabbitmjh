#include <iostream>
#include <functional>
#include <algorithm>
#include <string>
#include <math.h>
#include <utility>

using namespace std;
typedef long long ll;
typedef pair <int, int>p;
p arr[100005];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int a;
		scanf("%d", &a);
		arr[i].first = a;
		arr[i].second = i;
	}
	sort(arr, arr + n+1);
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum = max(sum, arr[i].second - i);
	}
	printf("%d", sum + 1);
	return 0;
}