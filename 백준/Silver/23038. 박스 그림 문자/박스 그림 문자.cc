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
int n, m;
char arr[905][905];
int x[4] = { -2,0,2,0 }, y[4] = { 0,-2,0,2 };


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n * 3; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i < n * 3; i += 3) {
		for (int j = 1; j < m * 3; j += 3) {
			for (int k = 0; k < 4; k++) {
				int nx = i + x[k];
				int ny = j + y[k];
				if (nx > 0 && n * 3 > nx && ny > 0 && m * 3 > ny && arr[nx][ny] == '#') {
 					arr[i][j] = '#';
					if (x[k] == -2)
						arr[nx + 1][ny] = '#';
					else if (x[k] == 2)
						arr[nx - 1][ny] = '#';
					else if (y[k] == -2)
						arr[nx][ny + 1] = '#';
					else if (y[k] == 2)
						arr[nx][ny - 1] = '#';
				}
			}
		}
	}

	for (int i = 0; i < n * 3; i++) {
		for (int j = 0; j < m * 3; j++) {
			cout << arr[i][j];
		}
		cout << endl;
	}
	return 0;
}