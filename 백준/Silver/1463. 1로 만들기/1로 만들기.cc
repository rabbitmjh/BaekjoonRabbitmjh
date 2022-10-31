#include<iostream>
#include<algorithm>
using namespace std;
long t,n,m;
long arr[1000005];
int main() {
	scanf("%ld", &n);
	arr[1] = 0;
	arr[2] = 1;
	arr[3] = 1;
	for (int i = 4; i <= n; i++) {
		arr[i] = arr[i - 1] + 1;
		if (i % 3 == 0)
			arr[i] = min(arr[i],arr[i / 3] + 1);
		if (i % 2 == 0)
			arr[i] = min(arr[i / 2] + 1,arr[i]);
    }
	printf("%ld", arr[n]);
	
	return 0;
}