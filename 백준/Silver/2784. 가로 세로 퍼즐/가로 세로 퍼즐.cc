#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

char arr[4][4];
int check[6];
vector <string> v;

int main() {
	FIO;
	int num = 6;
	while (num--) {
		string s; cin >> s;
		v.push_back(s);
	}

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (i == j)continue;
			for (int k = 0; k < 6; k++) {
				if (k == i || k == j)continue;

				arr[0][0] = v[i][0];
				arr[0][1] = v[i][1];
				arr[0][2] = v[i][2];

				arr[1][0] = v[j][0];
				arr[1][1] = v[j][1];
				arr[1][2] = v[j][2];

				arr[2][0] = v[k][0];
				arr[2][1] = v[k][1];
				arr[2][2] = v[k][2];

				int sum = 0, cnt;
				memset(check, 0, sizeof(check));
				for (int z = 0; z < 6; z++) {

					if (z != i && z != j && z != k) {
						for (int x = 0; x < 3; x++) {
							if (check[x])continue;
							cnt = 0;
							for (int y = 0; y < 3; y++)
								if (arr[y][x] == v[z][y])
									cnt++;
							if (cnt == 3) {
								sum++;
								check[x] = 1;
								break;
							}
						}
					}
				}
				if (sum == 3) {
					for (int x = 0; x < 3; x++) {
						for (int y = 0; y < 3; y++)
							cout << arr[x][y];
						cout << "\n";
					}
					return 0;
				}
			}
		}
	}
	cout << 0;
	return 0;
}