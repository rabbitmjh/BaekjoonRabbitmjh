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

int n, k, s, x, y, arr[205][205];
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
vector <pp> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;//k는 무의미
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			if (arr[i][j])
				v.push_back({ arr[i][j], { i,j } });
		}
	cin >> s >> x >> y;
	sort(v.begin(), v.end());

	while (s--) {
		int vs = v.size();
		for (int i = 0; i < vs; i++) {
			int virus = v[i].first;

			for (int j = 0; j < 4; j++) {
				int nx = v[i].second.first + dx[j];
				int ny = v[i].second.second + dy[j];

				if (1 <= nx && nx <= n && 1 <= ny && ny <= n && !arr[nx][ny]) {
					arr[nx][ny] = virus;
					v.push_back({ virus,{nx,ny} });
				}
			}
		}
		v.erase(v.begin(), v.begin() + vs);
	}

	cout << arr[x][y];

	return 0;
}