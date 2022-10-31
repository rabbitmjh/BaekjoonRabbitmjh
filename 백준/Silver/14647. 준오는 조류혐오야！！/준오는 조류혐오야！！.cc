#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
#include <utility>
#include <deque>
#include <string>
#include <limits>
#include <cmath>
#include <cstring>
#include <array>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, m, sum;
int arr[505][505], bingo[505][505];


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	//m:질량 s:속력 d:방향
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			int num = arr[i][j];
			while (num) {
				if (num % 10 == 9)bingo[i][j]++;
				num /= 10;
			}
			sum += bingo[i][j];
		}

	int nineX = 0, nineY = 0;
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < m; j++)
			cnt += bingo[i][j];
		nineX = max(cnt, nineX);
	}
	
	for (int i = 0; i < m; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++)
			cnt += bingo[j][i];
		nineY = max(cnt, nineY);
	}

	cout << sum - max(nineX, nineY);

	return 0;
}