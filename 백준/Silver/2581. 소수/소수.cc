#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int n,a,sum,n1,b;
int mini;

int main() {
	scanf("%d %d", &n,&a);
	for (n; n <= a; n++) {
		n1 = 0;
		if (n == 2 || n == 3) {
			if (n == 2&&b==0)mini = 2;
			else if (n == 3&&b==0)mini = 3;
			sum += n;
			b++;
		}
		else if (n == 1)continue;
		else if (n > 3) {
			for (int j = 1; j <= n; j++) {
				if (n%j == 0)n1++;
			}
			if (n1 <= 2) {
				sum += n;
				b++;
			}
		}
		if (b == 1 && n1 <= 2 && mini == 0&&n!=1)mini = n;
	}
	if (sum == 0)printf("%d", -1);
	else printf("%d\n%d", sum,mini);
	return 0;
}