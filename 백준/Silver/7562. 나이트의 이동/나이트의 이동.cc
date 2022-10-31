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
typedef pair<int, p> pp;

int arr[305][305],vis[305][305];
int dx[8] = { -2,-2,-1,-1,1,1,2,2 };
int dy[8] = { 1,-1,2,-2,2,-2,1,-1 };


int main() {
	int n; cin >> n;
	while (n--) {
		int x; cin >> x;
		int nx, ny; cin >> nx >> ny;
		int gox, goy; cin >> gox >> goy;
		queue <pp> q;
		q.push({ 0,{ nx,ny } });
		while (!q.empty()) {
			int a = q.front().second.first;
			int b = q.front().second.second;
			int cnt = q.front().first;
			q.pop();
			if (a == gox&&b == goy) {
				printf("%d\n", cnt);
				break;
			}
			for (int i = 0; i < 8; i++) {
				int c = a + dx[i];
				int d = b + dy[i];
				if (-1 < c&&c < x&&-1 < d&&d < x && !vis[c][d]) {
					q.push({ cnt + 1,{c,d} });
					vis[c][d] = 1;
				}
			}
		}
		memset(arr, 0, sizeof(arr));
		memset(vis, 0, sizeof(vis));
	}
	return 0;
}