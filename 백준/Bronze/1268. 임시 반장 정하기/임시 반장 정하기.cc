#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<ll, ll> p;
typedef pair<int, p> pp;

int n, arr[1005][5], ban[1005][1005], banjang = 1, score;
vector <int> v[10];

int main() {
	FIO;
	
	cin >> n;
	for (int i = 1;i <= n;i++)
		for (int j = 0;j < 5;j++)
			cin >> arr[i][j];
	
	for (int i = 1;i <= n;i++) {
		for (int j = 0;j < 5;j++) {
			for (int k = i + 1;k <= n;k++) {
				if (arr[i][j] == arr[k][j]) {
					ban[i][k] = 1;
					ban[k][i] = 1;
				}
			}
		}
	}

	for (int i = 1;i <= n;i++) {
		int sum = 0;
		for (int j = 1;j <= n;j++) {
			if (i == j)continue;
			if (ban[i][j])
				sum++;
		}
		if (score < sum) {
			score = sum;
			banjang = i;
		}
	}

	cout << banjang;

	return 0;
}
