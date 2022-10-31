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
typedef pair<string, int>p;
typedef pair<int, p> pp;

int arr[3][105];
int ans[3][105];

int main() {
	int n, cnt = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int day, milk;
		string name;
		cin >> day >> name >> milk;

		if (name == "Bessie")arr[0][day] = milk;
		else if (name == "Elsie")arr[1][day] = milk;
		else arr[2][day] = milk;
	}

	ans[0][0] = ans[1][0] = ans[2][0] = 7;

	for (int i = 0; i < 3; i++)
		for (int j = 1; j <= 100; j++)
			ans[i][j] = ans[i][j - 1] + arr[i][j];

	for (int i = 1; i <= 100; i++) {
		for (int j = 0; j < 3; j++) {
			bool chk1, chk2;
			int cmp1 = max(max(ans[0][i], ans[1][i]), ans[2][i]);
			int cmp2 = max(max(ans[0][i - 1], ans[1][i - 1]), ans[2][i - 1]);
			if (cmp1 == ans[j][i])chk1 = true;
			else chk1 = false;

			if (cmp2 == ans[j][i - 1])chk2 = true;
			else chk2 = false;

			if (chk1 != chk2) {
				cnt++;
				break;
			}
		}
	}
	cout << cnt;

	return 0;
}