#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <queue>
#include <cstring>
using namespace std;

int n, t;
int arr[100005], a,b,c;
int main() {
	scanf("%d %d %d", &a, &b, &c);
	for (int i = 1; i <= b; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = a; i >= 1; i--) {
		for (int j = 1; j <= b; j++) {
			if (i == c) {
				if (arr[j] >= i) {
					printf("%c",42);
					continue;
				}
				else {
					printf("%c",45);
					continue;
				}
			}
			else if (arr[j] >= i) {
				printf("%c",35);
				continue;
			}

			else if (i <= c &&j % 3 == 0) {
				printf("%c", 124);
				continue;
			}
			
			printf("%c",46);
		}
		printf("\n");
	}

	return 0;
}