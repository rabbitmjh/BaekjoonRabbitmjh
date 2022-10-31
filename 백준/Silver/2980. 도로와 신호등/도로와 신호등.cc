#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <string.h>
#include <utility>
using namespace std;
typedef pair<int, int> p;
typedef long long ll;

queue<pair<int, int>>q;
vector<vector<p>>v(1005);
int t, n, m;
int arr[9], arr1[9];
bool win=false;

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		int D, R, G;
		scanf("%d %d %d", &D, &R, &G);
		v[D].push_back({ R,G });
	}
	int time=0;
	for (int i = 1; i < m; i++) {
		if (v[i].size() > 0) {
			while (1) {
				if (time % (v[i][0].first + v[i][0].second) >= v[i][0].first) {
					break;
				}
				else time++;
			}
		}
		time++;
	}
	printf("%d", time);
	return 0;
}