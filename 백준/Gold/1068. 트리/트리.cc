#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
vector <vector<int>> v(100);

int n1, n2, sum, n, n3;

void lrp1(int i) {
	for (int j = 0; j < v[i].size(); j++) {
		if (v[i][j] == n2)v[i][j] = -1;
		if (v[i][j] != -1) {
			lrp1(v[i][j]);
		}
	}
}

void lrp(int i) {

	if (v[i].size() == 0)sum++;
	for (int j = 0; j < v[i].size(); j++) {
		if (v[i][j] != -1) {
			lrp(v[i][j]);

		}
		if (v[i].size() == 1) {
			if (v[i][j] == -1) {
				sum++;
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> n1;
		if (n1 == -1) {
			n3 = i;
			continue;
		}
		v[n1].push_back(i);
	}

	cin >> n2;
	if (n == 2) {
		printf("1");
		return 0;
	}
	if (n2 == n3) {
		printf("0");
		return 0;
	}
	lrp1(n3);

	lrp(n3);

	printf("%d", sum);
	return 0;
}
