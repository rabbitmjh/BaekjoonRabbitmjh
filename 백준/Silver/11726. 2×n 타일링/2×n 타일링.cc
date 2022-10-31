#include<cstdio>
#include<iostream>
using namespace std;

int n, t[1005];
int main() {
	t[1] = 1;
	t[2] = 2;
	scanf("%d", &n);
	for (int i = 3; i <= n; i++) {
		t[i] = (t[i - 2] + t[i - 1]) % 10007;
	}
	printf("%d", t[n]);
	return 0;
}