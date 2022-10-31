#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<string, int> p;
typedef pair<int, p> pp;

int k, n;
char arr[105][105];
vector <string> v, cmp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> k >> n;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		v.push_back(s);
		for (int j = 0; j < n; j++)
			arr[i][j] = '?';
		arr[i][i] = 'B';
	}

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n; j++) {
			string s; cin >> s;
			cmp.push_back(s);
		}

		for (int j = 0; j < n; j++) {
			bool check = true;
			for (int l = j + 1; l < n; l++) {
				if (cmp[l - 1] > cmp[l])
					check = false;

				if (!check) {
					int x, y;
					for (int m = 0; m < n; m++) {
						if (v[m] == cmp[j])x = m;
						if (v[m] == cmp[l])y = m;
					}
					arr[x][y] = '0';
					arr[y][x] = '1';
				}
			}
		}
		cmp.clear();
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << arr[i][j];
		cout << "\n";
	}

	return 0;
}