#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n,n1[105],sum;
int main() {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%1d", &n1[i]);
	}
	for (int i = 0; i < n; i++) {
		sum += n1[i];
	}
	printf("%d", sum);
	return 0;
}