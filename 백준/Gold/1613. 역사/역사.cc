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
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x,&y);
		arr[x][y] = -1;
		arr[y][x] = 1;
	}
	

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (arr[i][k] == 1 && arr[k][j] == 1) {
					arr[i][j] = 1;
				}
				if (arr[i][k] == -1 && arr[k][j] == -1) {
					arr[i][j] = -1;
				}
			}
		}
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		printf("%d\n", arr[x][y]);
	}


	return 0;
}