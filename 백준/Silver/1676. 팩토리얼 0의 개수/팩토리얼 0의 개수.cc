#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <string>
#include <string.h>
#include <math.h>
#include <limits.h>
using namespace std;
typedef pair<int, int> p;
typedef long long ll;
int n, cnt2, cnt5;
ll sum = 1;

int main() {
	cin >> n;
	if (!n) {
		printf("0");
		return 0;
	}
	for (int i = n; i > 0; i--) {
		sum *= i;
		while (sum % 2 == 0) {
			cnt2++;
			sum /= 2;
		}
		while (sum % 5 == 0) {
			cnt5++;
			sum /= 5;
		}
		sum %= 10;
	}

	printf("%d", min(cnt2, cnt5));

	return 0;
}