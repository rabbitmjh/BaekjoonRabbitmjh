#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, star[105], arr[400][400];

void go(int m) {
	if (n == m)return;
	int x = 1 + m * 2;
	int y = x;
	for (int i = x; i < x + star[n - m]; i++) {
		arr[y][i] = 1;
		arr[y + star[n - m] - 1][i] = 1;
	}
	for (int j = y; j < y + star[n - m]; j++) {
		arr[j][x] = 1;
		arr[j][x + star[n - m] - 1] = 1;
	}
	go(m + 1);
}

int main() {
	FIO;
	cin >> n;

	star[1] = 1, star[2] = 5;
	for (int i = 3; i <= n; i++) {
		int tmp = star[i - 1] * 2 - star[i - 2];
		star[i] = tmp;
	}
	go(0);
	for (int i = 1; i <= star[n] + 1; i++) {
		for (int j = 1; j <= star[n] + 1; j++) {
			if (arr[i][j])cout << "*";
			else cout << " ";
		}
		cout << "\n";
	}
	return 0;
}