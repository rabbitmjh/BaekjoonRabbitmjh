#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int>p;
typedef pair<p, int> pp;



int main() {
	int n1, n2, n3;
	int m1, m2, m3;
	cin >> n1 >> m1 >> n2 >> m2 >> n3 >> m3;
	for (int i = 1; i <= 100; i++) {
		int sum = 0;
		if (i % 3 == 1) {
			sum = m1 + m2;
			if (sum > n2) {
				m2 = n2;
				m1 = sum - n2;
			}
			else {
				m2 = sum;
				m1 = 0;
			}
		}
		else if (i % 3 == 2) {
			sum = m2 + m3;
			if (sum > n3) {
				m3 = n3;
				m2 = sum - n3;
			}
			else {
				m3 = sum;
				m2 = 0;
			}
		}
		else {
			sum = m3 + m1;
			if (sum > n1) {
				m1 = n1;
				m3 = sum - n1;
			}
			else {
				m1 = sum;
				m3 = 0;
			}
		}
	}
	printf("%d\n%d\n%d\n", m1, m2, m3);

	return 0;
}