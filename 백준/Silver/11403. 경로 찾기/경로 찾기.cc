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
int n;


int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &arr[i][j]);

	for (int j = 1; j <= n; j++)
		for (int k = 1; k <= n; k++)
			for (int m = 1; m <= n; m++)
				if (!arr[k][m] && arr[k][j] + arr[j][m] > 1)
					arr[k][m] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}

	return 0;
}