#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;

int a,arr[31],b,n;
int main() {
	scanf("%d", &n);
	while (n--) {
		scanf("%d %d", &a, &b);
		printf("%d %d\n", b * 2 - a, b -( b * 2 - a));

	}
	return 0;
}