#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, m, arr[70][70], ans;


int main() {
	FIO;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char a, b; string s; cin >> a >> s >> b;
		if (a == b)continue;
		arr[a - 'A'][b - 'A'] = 1;
	}

	for (int i = 0; i < 70; i++)
		for (int j = 0; j < 70; j++)
			for (int k = 0; k < 70; k++) {
				if (i == j)continue;
				if (arr[j][i] && arr[i][k])
					arr[j][k] = 1;
			}
	for (int i = 0; i < 70; i++)
		for (int j = 0; j < 70; j++)
			if (i != j && arr[i][j])
				ans++;

	cout << ans << "\n";
	for (int i = 0; i < 70; i++)
		for (int j = 0; j < 70; j++) {
			if (i == j)continue;

			if (arr[i][j])
				cout << char(i + 'A') << " => " << char(j + 'A') << "\n";
		}


	return 0;
}