#include <iostream>
#include <algorithm>
#include <cstring>
#include <functional>
#include <vector>
#include <queue>
#include <string>
using namespace std;
long long a, b;
int n;
char ch[10005];
int main() {
	scanf("%d %lld %lld", &n, &a, &b);
	long long sum=1;

	for (int i = 0; i < b; i++) {
		sum = (sum *= a) % 26;
	}
	
	for (int i = 0; i <= n; i++) {
		scanf("%c", &ch[i]);
	}

	for (int i = 1; i <= n; i++) {
		int sum1 = sum;
		if (ch[i] == ' ') {
			printf(" ");
			continue;
		}
		if (ch[i]- sum < 65) {
			int c = ch[i] - 'A';
			sum1 = sum1 - c - 1;
			printf("%c", 90- sum1);
		}
		else {
			printf("%c", ch[i] - sum);
		}
	}
	
	return 0;
}