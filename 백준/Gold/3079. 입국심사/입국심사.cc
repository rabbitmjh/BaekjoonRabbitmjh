#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <string>
using namespace std;

long long n, m, arr[1000005];


int main() {
	scanf("%lld %lld", &n, &m);
	long long L = 0, R =0;

	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
		if (R < arr[i]) {
			R = arr[i];
		}
	}
	R = R*m;
	
	long long a = 0;


	while (L < R) {
		long long mid = (L + R) / 2;
		long long sum = 0;
		for (int i = 0; i < n; i++) {
			sum += mid / arr[i];
		}
		if (sum < m) L = mid + 1;
		else R = mid;
	}
	printf("%lld", L);

	return 0;
}