#include<cstdio>
#include<iostream>
using namespace std;

int n,sum,num;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < 5; i++) {
		scanf("%d", &num);
		if (n == num)sum++;
	}
	printf("%d", sum);
	return 0;
}