#include<iostream>
#include<algorithm>
using namespace std;

int n, sum, n1, n2;
int main() {
	cin >> n >> n1 >> n2;
	if (n < n1 || n < n2)
		sum = -1;
	else {
		while (n1 != n2) {
			n1 = (n1 + 1) / 2;
			n2 = (n2 + 1) / 2;
			sum++;
		}
	}
	printf("%d", sum);
	return 0;
}