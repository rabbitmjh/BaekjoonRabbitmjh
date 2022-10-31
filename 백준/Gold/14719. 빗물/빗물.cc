#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int h, w, ans, arr[505][505], y;
vector <int> v;

int main() {
	FIO;
	cin >> h >> w;
	for (int i = 0; i < w; i++) {
		int n; cin >> n;
		v.push_back(n);
	}

	for (int i = 0; i < w; i++) {
		y = max(y, v[i]);
		for (int j = 0; j < v[i]; j++)
			arr[i][j] = 1;
	}

	for (int i = 0; i < y; i++) {
		int cnt = 0;
		for (int j = 1; j < w; j++) {
			if (arr[j-1][i] && !arr[j][i])
				cnt++;
			else if (cnt && !arr[j][i]) cnt++;

			if (arr[j][i]) {
				ans += cnt;
				cnt = 0;
			}
		}
	}
	cout << ans;
	return 0;
}