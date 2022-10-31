#include <iostream>
using namespace std;

int gcd(int b1, int b2) {
	if (b2)return gcd(b2, b1%b2);
	else return b1;
}

int main() {
	int b1, b2;
	cin >> b1 >> b2;

	if (b2 > b1)swap(b2, b1);

	printf("%d\n", gcd(b1, b2));
	printf("%d", b1*b2/gcd(b1, b2));

	return 0;
}