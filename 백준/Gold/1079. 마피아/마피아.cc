#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, m, r[20][20], score[20], cnt, ans;

void dfs(int num, int d) {
	if (num == 1) {
		ans = max(ans, d);
		return;
	}

	if (num % 2 == 1) {//낮
		int die, mscore = 0;
		for (int i = 0; i < n; i++) {
			if (mscore < score[i]) {
				die = i;
				mscore = score[i];
			}
		}
		if (die == m) {
			ans = max(ans, d);
			return;
		}

		score[die] = -1e9;
		dfs(num - 1, d);
		score[die] = mscore;
	}
	else {//밤
		for (int i = 0; i < n; i++) {
			if (i == m || score[i] == -1e9)
				continue;

			int tmp = score[i];
			score[i] = -1e9;
			for (int j = 0; j < n; j++) {
				if (score[j] != -1e9)
					score[j] += r[i][j];
			}
			dfs(num - 1, d + 1);

			for (int j = 0; j < n; j++) {
				if (score[j] != -1e9)
					score[j] -= r[i][j];
			}
			score[i] = tmp;
		}
	}
}

int main() {
	FIO;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> score[i];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> r[i][j];
	cin >> m;

	dfs(n, 0);

	cout << ans;

	return 0;
}