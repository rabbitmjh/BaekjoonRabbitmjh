#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <utility>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
vector <vector<int>> v(105);
int arr[105][105],ch[105],ans[105];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	ans[1] = 1;
	for (int i = 2; i <= n; i++) {
		memset(ch, 0, sizeof(ch));
		for (int j = 0; j < v[i].size(); j++)
			ch[ans[v[i][j]]]++;
		for (int j = 1; j <= 4; j++) {
			if (ch[j] == 0) {
				ans[i] = j;
				break;
			}
		}
	}
	for (int i = 1; i <= n; i++)printf("%d", ans[i]);
	return 0;
}