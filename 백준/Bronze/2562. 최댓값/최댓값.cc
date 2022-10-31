#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;

int a,arr[9],b;
int main() {
	for (int i = 0; i < 9; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < 9; i++) {
		if (a < arr[i]) {
			b = i;
			a = arr[i];
		}
	}
	printf("%d\n%d", a, b+1);
	return 0;
}