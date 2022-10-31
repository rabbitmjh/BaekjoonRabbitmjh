#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
using namespace std;
vector <int> v;
float arr[2][2],sum=0;
int  n1;
string n;
int main() {
	for (int i = 0; i < 2; i ++ ) {
		for (int j = 0; j < 2; j++) {
			scanf("%f", &arr[i][j]);
		}
	}
	for (int i = 0; i < 4; i++) {
		if (sum < ((arr[0][0] / arr[1][0]) + (arr[0][1] / arr[1][1]))) {
			sum = ((arr[0][0] / arr[1][0]) + (arr[0][1] / arr[1][1]));
			n1 = i;
		}
		int a = 0;
		a = arr[0][0];
		arr[0][0] = arr[1][0];
		arr[1][0] = arr[1][1];
		arr[1][1] = arr[0][1];
		arr[0][1] = a;
	}
	printf("%d", n1);
	return 0;
}
