#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;

int a,arr[31],b;
int main() {
	for (int i = 0; i < 28; i++) {
		scanf("%d", &a);
		arr[a] = 1;
	}
	for (int i = 1; i <= 30; i++) {
		if (arr[i] == 0) {
			printf("%d\n", i);
		}
	}
	return 0;
}