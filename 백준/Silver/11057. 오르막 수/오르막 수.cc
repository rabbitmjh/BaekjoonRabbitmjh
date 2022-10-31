#include <iostream>
#include <algorithm>
using namespace std;
int n;
long long arr[10],sum=0;

int main() {
	cin >> n;
	
	for (int i = 0; i < 10; i++) {
		arr[i] = 1;
	}
	for (int i = 2; i<=n;i++) {
		for (int j = 1; j < 10; j++) {
			arr[j] = (arr[j] + arr[j - 1])%10007;
		}
	}
	for (int i = 0; i < 10; i++) {
		sum += arr[i] % 10007;

	}

	printf("%lld", sum%10007);
	return 0;
}