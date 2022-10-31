#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <string>
#include <string.h>
#include <math.h>
#include <limits.h>
using namespace std;

int j, a, sum;
char arr[1000005];

int main() {
	scanf("%d %d", &j, &a);
	for (int i = 1; i <= j; i++)
		scanf(" %c", &arr[i]);
	
	for (int i = 0; i < a; i++) {
		char size;
		int num;
		scanf(" %c %d", &size, &num);
		if (arr[num] <= size) {
			sum++;
			arr[num] = 'a';
		}
	}
	
	printf("%d", sum);
	return 0;
}