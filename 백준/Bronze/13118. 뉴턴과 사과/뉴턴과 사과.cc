#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <queue>
#include <cstring>
using namespace std;

int n, t;
int arr[4], b, c, d, e, f, g;
int main() {
	scanf("%d %d %d %d", &arr[0],&arr[1],&arr[2],&arr[3]);
	scanf("%d %d %d", &e, &f, &g);
	for (int i = 0; i < 4; i++) {
		if (e == arr[i]) {
			printf("%d", i+1);
			return 0;
		}
	}
	printf("0");


	return 0;
}