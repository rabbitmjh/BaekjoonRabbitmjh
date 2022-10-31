#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <queue>
#include <string>
#include <cstring>
using namespace std;
int arr[10005];

int n, c,sum,a;
int go(int i, int a) {
	if (arr[i] > c || a > c)return 0;
	if (arr[i] == c || a == c) {
		sum++;
		return 0;
	}
	if (arr[i] < c) {
		a += arr[i];
		if (a == c) {
			sum++;
			return 0;
		}
		if (arr[i + 1] + a>c)return 0;
		if (i != n) {
			go(i + 1, a);
			return 0;
		}
	}


}


int main() {
	scanf("%d %d", &n,&c);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < n; i++) {
		a = 0;
		go(i,0);
	}
	printf("%d", sum);

	return 0;
}