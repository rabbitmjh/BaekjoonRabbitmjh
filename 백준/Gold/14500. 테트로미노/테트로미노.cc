#include <iostream>
#include <algorithm>
#include <utility>
#include <functional>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
#include <limits>
using namespace std;
typedef long long ll;
typedef pair <int, int> p;
typedef pair <int, p> pp;
//백준14500 테트로미노
int n, m, ans;
int dx[4] = {0, 0, -1, 1}, dy[4] = {1, -1, 0, 0};
int arr[505][505], vis[505][505];


void dfs(int x, int y, int cnt, int sum){
	if(cnt == 4) {
		ans = max(ans, sum);
		return;
	}
	vis[x][y] = 1;
	for(int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(-1 < nx&&nx < n&&-1 < ny&&ny < m&&vis[nx][ny] == 0){
			dfs(nx, ny, cnt + 1, sum + arr[nx][ny]);
			
		}
	}
	vis[x][y] = 0;
	return;
}
void bolock(int x, int y){
	if(x - 1 > -1&&x + 1 < n&&y + 1 < m) 
		ans = max(ans, arr[x][y] + arr[x - 1][y] + arr[x + 1][y] + arr[x][y + 1]);
	if(x - 1 > -1&&y + 1 < m&&y - 1 > -1)
		ans = max(ans, arr[x][y] + arr[x - 1][y] + arr[x][y + 1] + arr[x][y - 1]);
	if(y + 1 < m&&y - 1 > -1 &&x + 1 < n)
		ans = max(ans, arr[x][y] + arr[x][y + 1] + arr[x][y - 1] + arr[x + 1][y]);
	if(x - 1 > -1&&x + 1 < n&&y - 1 > -1)
		ans = max(ans, arr[x][y] + arr[x - 1][y] + arr[x + 1][y] + arr[x][y - 1]);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> arr[i][j];
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++){
			dfs(i, j, 1, arr[i][j]);
			bolock(i, j);
		}
	
	
	cout << ans << endl;
	
    return 0;
}
