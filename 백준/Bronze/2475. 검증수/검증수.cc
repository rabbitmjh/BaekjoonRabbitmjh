#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<string.h>
using namespace std;
int n[5],sum;
int main() {
	scanf("%d %d %d %d %d", &n[0], &n[1], &n[2], &n[3], &n[4]);
	int n1 = 5;
	while (n1--) {
		sum += n[n1]*n[n1];
	}
	printf("%d", sum % 10);
}