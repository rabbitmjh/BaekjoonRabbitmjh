#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, k, winLose[10][10], arr[20][3], score[3];
int ptr[3], used[10], ans;

void go(int p1, int p2) { 
	if (score[0] >= k) {
		ans = 1;
		return;
	}

	if (score[1] >= k || score[2] >= k) return;

	if (ptr[0] > n) return;
	if (p1 > p2) swap(p1, p2);

	if (winLose[arr[ptr[p1]++][p1]][arr[ptr[p2]++][p2]] == 2) {
		score[p1]++;
		go(p1, 3 - p1 - p2);
	}
	else {
		score[p2]++;
		go(p2, 3 - p1 - p2);
	}
}

void slove(int depth) {
	if (ans) return;

	if (depth == n) {
		go(0, 1);
		
		ptr[0] = ptr[1] = ptr[2] = 0;
		score[0] = score[1] = score[2] = 0;

		return;
	}

	for (int i = 1; i <= n; i++) {
		if (ans) return;

		if (used[i]) continue;

		arr[depth][0] = i;
		used[i] = 1;
		slove(depth + 1);
		used[i] = 0;
	}
}

int main() {
    FIO;

	cin >> n >> k;

	if (k > n) {
		cout << 0;
		return 0;
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> winLose[i][j];

	for (int i = 1; i <= 2; i++)
		for (int j = 0; j < 20; j++)
			cin >> arr[j][i];

	slove(0);

	cout << ans;

	return 0;
}