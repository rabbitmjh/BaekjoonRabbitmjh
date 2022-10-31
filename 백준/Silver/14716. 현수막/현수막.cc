#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<functional>
#include<math.h>
#define inf 100000000
using namespace std;

int arr[250][250];
int check[250][250];
int dr[8] = { 0,0,1,-1,1,1,-1,-1 };
int dc[8] = { 1,-1,0,0,1,-1,1,-1 };
int n,n1;
int dfs(int r, int c) {

	int ret = 1;
	for (int k = 0; k < 8; k++) {
		int nr = r + dr[k];
		int nc = c + dc[k];
		if (0 <= nr&&nr < n && 0 <= nc&&nc < n1&&check[nr][nc] == 0 && arr[nr][nc] == 1) {
			check[nr][nc] = 1;
			ret += dfs(nr, nc);
		}
	}
	return ret;
}

int main(void) {
	scanf("%d %d", &n,&n1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n1; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	vector<int> ans;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n1; j++) {
			if (check[i][j] == 0 && arr[i][j] == 1) {
				check[i][j] = 1;
				ans.push_back(dfs(i, j));
			}
		}
	}
	printf("%d\n", ans.size());
	
}