#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
vector<vector<int>>v(105);
queue<pair<int, int>>q;
int arr[405][405],check[105][105];
int n,m,a=1000000,b;

int main() {
	scanf("%d %d", &n, &m);
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)arr[i][j] = 0;
			else arr[i][j] = 1e9;
		}
	}
	for (int i = 0; i < m; i++) {
		int x, y,z;
		scanf("%d %d", &x, &y);
		scanf("%d", &z);
		if (arr[x][y]>z)arr[x][y] = z;

	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (arr[i][j]>arr[i][k] + arr[k][j]) {
					arr[i][j] = arr[i][k] + arr[k][j];
				}
				
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] == 1e9)printf("0 ");
			else if (i == j)printf("0 ");
			else printf("%d ", arr[i][j]);
		}
		printf("\n");
	}


	return 0;
}