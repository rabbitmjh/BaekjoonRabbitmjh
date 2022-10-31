#include <iostream>
#include <algorithm>
#include <functional>
#include <utility>
#include <math.h>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair <int, int> p;


int n, m, u, v, b, k;
int arr[255][255];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == j)arr[i][j] = 0;
			else arr[i][j] = 100000000;
		}
	}
	while (m--) {
		scanf("%d %d %d", &u, &v, &b);
		if (b == 0) {
			arr[u][v] = 0;
			arr[v][u] = 1;
		}
		else {
			arr[u][v] = 0;
			arr[v][u] = 0;
		}
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
	scanf("%d", &k);
	while (k--) {
		scanf("%d %d", &u, &v);
		printf("%d\n", arr[u][v]);
	}

	return 0;
}