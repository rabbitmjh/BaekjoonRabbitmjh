#include <iostream>
#include <algorithm>
#include <cstring>
#include <functional>
#include <vector>
#include <queue>
#include <string>
#include <string.h>
using namespace std;

int n,m,q,z;
int arr[20000005];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		arr[10000000 + a]++;
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &z);
		printf("%d ", arr[10000000 + z]);
	}

	return 0;
}
