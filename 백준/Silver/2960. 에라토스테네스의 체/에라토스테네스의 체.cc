#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
using namespace std;
int arr[1005];
int check[1005];
int n, n1, sum;

int go(int a,int b) {
	for (int i = a; i <= n; i++) {
		if (i%a == 0&&arr[i]==0) {
			sum++;
			arr[i] = 1;
			if (sum == b) {
				printf("%d", i);
				return 0;
			}
		}
	}
	return 1;
}

int main() {
	scanf("%d %d", &n,&n1);
	for (int i = 4; i <= 1000; i++) {
		for (int j = 2; j < i; j++) {
			if (i%j == 0) {
				check[i] = 1;
				break;
			}
		}
	}
	
	for (int i = 2; i <= n; i++) {
		if (go(i, n1) == 0)break;

	}
	return 0;
}
