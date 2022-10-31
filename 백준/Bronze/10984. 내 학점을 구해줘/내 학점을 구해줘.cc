#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <string>
#include <string.h>
#include <math.h>
#include <limits.h>
using namespace std;
typedef pair<int, int> p;

int t, n, c, sum;
float g, gpa;
int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		sum = 0, gpa = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d %f", &c, &g);
			sum += c;
			gpa += (float)(c * g);
		}
		gpa = gpa / (float)sum;
		printf("%d %.1f\n", sum, gpa);
	}
	return 0;
}