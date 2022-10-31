#include<iostream>
using namespace std;
int n, k, m;
int arr[10005],a[105];
int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	arr[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j >= a[i]) {
				arr[j] += arr[j - a[i]];
			}
		}
	}
	printf("%d", arr[k]);

	return 0;
}