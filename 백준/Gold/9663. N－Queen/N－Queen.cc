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
typedef pair<p, p> pp;

int n, ans;
vector <pp> v;

void dfs(int x, int y) {


	if (v.size() == n) {//퀸이 n개일때 방법의 수++ 및 return
		ans++;
		v.pop_back();
		return;
	}

	for (int j = 1; j <= n; j++) {//y값
		bool check = true, skipX = false, skipY = false;

		for (int k = 0; k < v.size(); k++) {
			int nx = v[k].second.first, ny = v[k].second.second;
			int dia1 = v[k].first.first, dia2 = v[k].first.second;
			if (nx == x) {//가로체크
				check = false;
				skipX = true;
				break;
			}
			else if (ny == j) {//세로 체크
				check = false;
				skipY = true;
				break;
			}
			else if (dia1 == x + j || dia2 == x - j) {//대각선 체크
				check = false;
				break;
			}
		}
		if (skipX)
			break;
		if (skipY)
			continue;
		if (check) {
			v.push_back({ { x + j,x - j }, { x, j } });
			dfs(x + 1, 1);
		}
	}

	v.pop_back();
	return;
}


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		v.push_back({ { 1 + i,1 - i }, { 1,i } });
		dfs(2, i);
		v.clear();
	}
	cout << ans;

	return 0;
}