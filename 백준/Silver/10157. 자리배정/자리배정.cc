#include <iostream>
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
#include <deque>
using namespace std;
typedef long long ll;
typedef pair<int, int>p;
typedef pair<string, p> pp;

int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
int r, c, k;
int arr[1005][1005];

int main() {
	cin >> r >> c >> k;
	for (int i = 0; i <= 1001; i++) {
		arr[i][0] = 1;
		arr[0][i] = 1;
		arr[c + 1][i] = 1;
		arr[i][r + 1] = 1;
	}

	bool check = true;
	int x = 0, y = 1, cnt = 0;
	for (int i = 1; i <= r * c; i++) {
		x += dx[cnt];
		y += dy[cnt];
		arr[x][y] = 1;

		if (arr[x + dx[cnt]][y + dy[cnt]])cnt = (cnt + 1) % 4;
		if (i == k) {
			printf("%d %d", y, x);
			check = false;
		}
	}
	if (check == true)printf("0");
	return 0;
}