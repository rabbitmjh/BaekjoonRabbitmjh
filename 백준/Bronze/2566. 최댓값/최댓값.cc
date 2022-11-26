#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int arr[10][10], x, y, mx = -1;

int main() {
	FIO;
	for (int i = 1; i <= 9; i++)
		for (int j = 1; j <= 9; j++) {
			cin >> arr[i][j];
			if (mx < arr[i][j]) {
				mx = arr[i][j];
				x = i;
				y = j;
			}
		}

	cout << mx << "\n" << x << " " << y;
	return 0;
}