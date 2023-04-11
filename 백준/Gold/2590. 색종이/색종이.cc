#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int square[7], ans;

int main() {
	FIO;
	for (int i = 1; i <= 6; i++)
		cin >> square[i];
	ans = square[6];

	ans += square[5];
	square[1] -= 11 * square[5];

	ans += square[4];
	square[2] -= 5 * square[4];

	if (square[3] >= 4) {
		ans += square[3] / 4;
		square[3] = square[3] % 4;
	}
	if (square[3] > 0) {
		if (square[3] == 1) {
			square[2] -= 5;
			square[1] -= 7;
		}
		else if (square[3] == 2) {
			square[2] -= 3;
			square[1] -= 6;
		}
		else {
			square[2]--;
			square[1] -= 5;
		}
		ans++;
	}

	if (square[2] >= 9) {
		ans += square[2] / 9;
		square[2] = square[2] % 9;
	}
	if (square[2] > 0) {
		if (square[2] == 1)
			square[1] -= 32;
		else if (square[2] == 2)
			square[1] -= 28;
		else if (square[2] == 3)
			square[1] -= 24;
		else if (square[2] == 4)
			square[1] -= 20;
		else if (square[2] == 5)
			square[1] -= 16;
		else if (square[2] == 6)
			square[1] -= 12;
		else if (square[2] == 7)
			square[1] -= 8;
		else
			square[1] -= 4;
		ans++;
	}
	else
		square[1] += square[2] * 4;
	
	if (square[1] >= 36) {
		ans += square[1] / 36;
		square[1] = square[1] % 36;
	}
	if (square[1] > 0)
		ans++;

	cout << ans;

	return 0;
}