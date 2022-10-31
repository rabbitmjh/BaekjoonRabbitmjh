#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <cstring>
#include <utility>
#include <limits.h>
#include <math.h>
using namespace std;
typedef pair<int, int> p;
typedef pair<int, p> pp;
vector<vector<int>>v(105);
queue<p>q;
int arr[105][105];
int n, m, sum, a, b;


int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (!arr[i][j])arr[i][j] = 10000;
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (arr[i][j] > arr[i][k] + arr[k][j])
					arr[i][j] = arr[i][k] + arr[k][j];

	a = 1e9;
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= n; j++) {
			sum += arr[i][j];
		}
		if (a > sum) {
			a = sum;
			b = i;
		}
	}
	cout << b;
	return 0;
}