#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;
int sum, a, b;
int main() {
	scanf("%d", &a);
	for (int i = 0; i < 6; i++) {
		if (a == 0)break;
		if (a%2 == 0) {
			a = a / 2;
			if (a % 2 == 0) {
				a = a / 2;
				if (a % 2 == 0) {
					a = a / 2;
					if (a % 2 == 0) {
						a = a / 2;
						if (a % 2 == 0) {
							a = a / 2;
							if (a % 2 == 0) {
								sum++;
								break;
							}
						}
					}
				}
			}
		}
		a = a / 2;
		sum++;
		
	}
	printf("%d", sum);
	return 0;
}