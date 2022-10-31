#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
vector<int>temp;
queue<pair<int, int>>q;
int arr[405][405], path[105][105];
int n, m, a = 1000000, b;

void go(int here, int en) {
	if (path[here][en] != 0) {
		go(here, path[here][en]);
		temp.push_back(path[here][en]);
		go(path[here][en], en);
	}
}

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)arr[i][j] = 0;
			else arr[i][j] = 1e9;
		}
	}
	for (int i = 0; i < m; i++) {
		int x, y, z;
		scanf("%d %d", &x, &y);
		scanf("%d", &z);
		if (arr[x][y] > z)arr[x][y] = z;

	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				if (arr[i][j] > arr[i][k] + arr[k][j]) {
					arr[i][j] = arr[i][k] + arr[k][j];
					path[i][j] = k;
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

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)printf("0\n");
			else if (arr[i][j] == 1e9)printf("0\n");
			else {
				go(i,j);
				printf("%d ", temp.size()+2);
				printf("%d ", i);
				for (int k = 1; k <= temp.size(); k++) {
					printf("%d ", temp[k - 1]);
				}
				printf("%d", j);
				printf("\n");
				temp.clear();
			}

		}
	}

	return 0;
}