#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
using namespace std;
char arr[10][10];
int n, n1, sum;

int main() {
	for (int i = 1; i <= 8; i++) {
		for (int j = 1; j <= 8; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= 8; i++) {
		for (int j = 1; j <= 8; j++) {
			if (i % 2 == 0 && j % 2 == 0 && arr[i][j] == 'F')sum++;
			else if (i % 2 == 1 && j % 2 == 1 && arr[i][j] == 'F')sum++;
		}
	}

	printf("%d", sum);

	return 0;
}
