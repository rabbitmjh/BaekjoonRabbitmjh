#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int n,a,sum,n1;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		n1 = 0;
		if (a == 2 || a == 3) {
			sum++;
		}
		else if (a == 1)continue;
		else if(a > 3){
			for (int j = 1; j <= a; j++) {
				if (a%j == 0)n1++;
			}
			if (n1 <= 2)sum++;
		}
	}
	printf("%d", sum);
	return 0;
}