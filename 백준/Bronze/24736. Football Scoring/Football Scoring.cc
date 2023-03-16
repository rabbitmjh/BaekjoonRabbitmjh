#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int arr[2][5];

int main() {
	FIO;
	for (int i = 0;i < 2;i++)
		for (int j = 0;j < 5;j++)
			cin >> arr[i][j];

	cout << arr[0][0] * 6 + arr[0][1] * 3 + arr[0][2] * 2 + arr[0][3] + arr[0][4] * 2 << " ";
	cout << arr[1][0] * 6 + arr[1][1] * 3 + arr[1][2] * 2 + arr[1][3] + arr[1][4] * 2;

	return 0;
}