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
typedef pair<int, int>p;
typedef pair<int, p> pp;

int fir[4], sec[4], truck[4];
int arr[2005][2005];
int ans;

int main() {
	cin >> fir[0] >> fir[1] >> fir[2] >> fir[3];
	cin >> sec[0] >> sec[1] >> sec[2] >> sec[3];
	cin >> truck[0] >> truck[1] >> truck[2] >> truck[3];
	int mnx = min(fir[0], sec[0]), mxx = max(fir[2], sec[2]);
	int mny = min(fir[1], sec[1]), mxy = max(fir[3], sec[3]);

	for (int i = fir[0]; i < fir[2]; i++)
		for (int j = fir[1]; j < fir[3]; j++)
			arr[i + 1000][j + 1000] = 1;

	for (int i = sec[0]; i < sec[2]; i++)
		for (int j = sec[1]; j < sec[3]; j++)
			arr[i + 1000][j + 1000] = 1;

	for (int i = truck[0]; i < truck[2]; i++)
		for (int j = truck[1]; j < truck[3]; j++)
			arr[i + 1000][j + 1000] = 0;

	for (int i = mnx; i < mxx; i++)
		for (int j = mny; j < mxy; j++)
			if (arr[i + 1000][j + 1000])ans++;

	cout << ans;

	return 0;
}