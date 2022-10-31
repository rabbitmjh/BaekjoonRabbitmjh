#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n1[3], n2[3],n;
int main() {
	for (int i = 0; i < 3; i++) scanf("%1d", &n1[i]);
	for (int i = 0; i < 3; i++) scanf("%1d", &n2[i]);
	n = n1[0];
	n1[0] = n1[2];
	n1[2] = n;
	n = n2[0];
	n2[0] = n2[2];
	n2[2] = n;
	if (n1[0] == n2[0]) {
		if (n1[1] > n2[1]) {
			for (int i = 0; i < 3; i++) {
				printf("%d", n1[i]);
			}
		}
		else if (n1[1] == n2[1]) {
			if (n1[2] > n2[2]) {
				for (int i = 0; i < 3; i++) {
					printf("%d", n1[i]);
				}
			}
			else {
				for (int i = 0; i < 3; i++) {
					printf("%d", n2[i]);
				}
			}
		}
		else {
			for (int i = 0; i < 3; i++) {
				printf("%d", n2[i]);
			}
		}
	}
	else if (n1[0] > n2[0]) {
		for (int i = 0; i < 3; i++) {
			printf("%d", n1[i]);
		}
	}
	else {
		for (int i = 0; i < 3; i++) {
			printf("%d", n2[i]);
		}
	}
	return 0;
}