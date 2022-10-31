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
char arr[105][105], ans[105][105];


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
			
	for (int i = m - 1; i > -1; i--) {
		for (int j = 0; j < n; j++) {
			ans[m - 1 - i][j] = arr[j][i];
			if (ans[m - 1 - i][j] == 45)
				ans[m - 1 - i][j] = 124;
			else if (ans[m - 1 - i][j] == 124)
				ans[m - 1 - i][j] = 45;
			else if (ans[m - 1 - i][j] == 47)
				ans[m - 1 - i][j] = 92;
			else if (ans[m - 1 - i][j] == 92)
				ans[m - 1 - i][j] = 47;
			else if (ans[m - 1 - i][j] == 94)
				ans[m - 1 - i][j] = 60;
			else if (ans[m - 1 - i][j] == 60)
				ans[m - 1 - i][j] = 118;
			else if (ans[m - 1 - i][j] == 118)
				ans[m - 1 - i][j] = 62;
			else if (ans[m - 1 - i][j] == 62)
				ans[m - 1 - i][j] = 94;
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			cout << ans[i][j];
		cout << "\n";
	}
	return 0;
}