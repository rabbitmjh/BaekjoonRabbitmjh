#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <stdlib.h>

using namespace std;
int n,n1,n2,a,sum;
vector <vector<int>> v(100005);
int main() {
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		scanf("%d %d",&n1,&n2);
		v[n2].push_back(n1);
	}
	if (n == 0 || n == 1) {
		printf("0");
		return 0;
	}
	for (int i = 0; i <= n; i++) {
		sort(v[i].begin(), v[i].end());
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < v[i].size(); j++) {
			if (j == 0) {
				sum += abs(v[i][j + 1] - v[i][j]);
			}
			else if (j == v[i].size() - 1) {
				sum += abs(v[i][j] - v[i][j - 1]);
			}
			else {
				if (abs(v[i][j + 1] - v[i][j])>abs(v[i][j] - v[i][j - 1])) {
					sum += abs(v[i][j] - v[i][j - 1]);
				}
				else {
					sum += abs(v[i][j + 1] - v[i][j]);
				}
			}
		}
	}
	printf("%d", sum);
	return 0;
}