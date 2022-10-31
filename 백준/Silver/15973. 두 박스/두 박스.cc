#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <stdlib.h>

using namespace std;
int arr[3][5];
int p, l, f, n;

int main() {
	for (int i = 1; i <= 2; i++) {
		for (int j = 1; j <= 4; j++) {
			cin >> arr[i][j];
		}
	}
	if (arr[1][1] > arr[2][3] || arr[1][2] > arr[2][4] || arr[1][3] < arr[2][1] || arr[1][4] < arr[2][2]) {
		printf("NULL");
		return 0;
	}
	if (arr[1][1] == arr[2][3]) {
		if (arr[1][2] == arr[2][4] || arr[1][4] == arr[2][2]) {
			p++;
		}
	}
	else if (arr[1][3] == arr[2][1]) {
		if (arr[1][2] == arr[2][4] || arr[1][4] == arr[2][2]) {
			p++;
		}
	}

	// point 구별

	if (arr[1][2] == arr[2][4])l++;
	else if (arr[1][3] == arr[2][1])l++;
	else if (arr[1][4] == arr[2][2])l++;
	else if (arr[1][1] == arr[2][3])l++;
	// line 구별

	if (p == 1) {
		printf("POINT");
	}
	else if (l == 1) {
		printf("LINE");
	}
	else {
		printf("FACE");
	}

	
	return 0;
}
