#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int n,arr[15][15],check[15];
vector <int> v;

void dfs(int sum, int a,int b,int c) {
	check[a] = 1;
	for (int i = 0; i < n; i++) {
		if (b == n-1) {
			if (arr[a][c] == 0)return;
			v.push_back(sum+arr[a][c]);
			return;
		}
		if (a == i)continue;
		else if (arr[a][i] == 0)continue;
		else if (check[i] == 1)continue;
		else {
			dfs(sum + arr[a][i], i, b+1,c);
			check[i] = 0;
		}
	}


}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		check[i] = 1;
		dfs(0,i,0,i);
		memset(check, 0, sizeof(check));
		check[i] = 0;
	}
	sort(v.begin(), v.end());
	printf("%d", v.front());
	return 0;
}