#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define FIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, arr[1005][1005];
p pro, sung;

int main() {
	FIO;
	cin >> n;
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 5)
				pro = { i,j };
			else if (arr[i][j] == 2)
				sung = { i,j };
		}

	int xa = pro.first;
	int xb = sung.first;
	int ya = pro.second;
	int yb = sung.second;
	pro.first = min(xa, xb);pro.second = min(ya, yb);
	sung.first = max(xa, xb);sung.second = max(ya, yb);
	int dis = pow((pro.first - sung.first), 2) + pow((pro.second - sung.second), 2);
	if (dis < 25) {
		cout << 0;
		return 0;
	}
	int cnt = 0;
	if (pro.first == sung.first) {
		for (int i = pro.second + 1;i < sung.second;i++)
			if (arr[pro.first][i] == 1)cnt++;
		if (cnt > 2)
			cout << 1;
		else
			cout << 0;
		return 0;
	}
	if (pro.second == sung.second) {
		for (int i = pro.first + 1;i < sung.first;i++)
			if (arr[i][pro.second] == 1)cnt++;
		if (cnt > 2)
			cout << 1;
		else
			cout << 0;
		return 0;
	}

	for (int i = pro.first;i <= sung.first;i++) 
		for (int j = pro.second;j <= sung.second;j++)
			if (arr[i][j] == 1)
				cnt++;

	if (cnt > 2)cout << 1;
	else cout << 0;

	return 0;
}