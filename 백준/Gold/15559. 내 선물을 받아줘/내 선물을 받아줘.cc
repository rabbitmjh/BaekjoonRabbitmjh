#include <iostream>
#include <algorithm>
#include <functional>
#include <math.h>
#include <vector>
#include <queue>
using namespace std;
int n, m, cnt, sum = 1;
char arr[1005][1005];
int cycle[1005][1005];

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		scanf("%s", arr[i]);

	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) {
			if (cycle[i][j])continue;
			int y = i, x = j;

			while (!cycle[y][x]) {
				cycle[y][x] = sum;
				if (arr[y][x] == 'S')y++;
				else if (arr[y][x] == 'E')x++;
				else if (arr[y][x] == 'N')y--;
				else x--;
			}
			cnt += cycle[y][x] == sum++;
		}

	printf("%d", cnt);
	return 0;
}