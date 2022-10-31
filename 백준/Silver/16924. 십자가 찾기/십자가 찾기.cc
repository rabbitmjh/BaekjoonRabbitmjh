#include <iostream>
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
using namespace std;
typedef pair<int, int> p;
typedef pair<p, int> pp;
vector <pp> v;
char arr[105][105];
int check[105][105];
int n, m;

void cross(int x, int y) {
	int Lx = x, Rx = x, Uy = y, Dy = y, count = 0;
	while (1) {
		Lx--, Rx++;
		Uy++, Dy--;
		if (arr[Lx][y]==42 && arr[Rx][y]==42 && arr[x][Uy]==42 && arr[x][Dy] == 42) {
			count++;
			check[Lx][y]++, check[Rx][y]++, check[x][Uy]++, check[x][Dy]++, check[x][y]++;
			v.push_back({ { x,y },count });
		}
		else break;
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		scanf("%s", &arr[i]);
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) 
			if (arr[i][j] == 42) cross(i, j);

	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == '*') sum1++;
			if (check[i][j] > 0)sum2++;
		}

	if (sum1 != sum2) {
		printf("-1\n");
		return 0;
	}
	else {
		printf("%d\n", v.size());
		for (int i = 0; i < v.size(); i++)
			printf("%d %d %d\n", v[i].first.first + 1, v[i].first.second + 1, v[i].second);
	}
	return 0;
}