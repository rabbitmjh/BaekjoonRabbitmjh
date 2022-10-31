#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, arr[105][105], x,y;

int main(){
	FIO;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				x = i;
				y = j;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] == 1) {
				bool check = false;
				if (abs(y - j) == 0 && abs(x - i) % 2 == 0)
					check = true;
				else if ((abs(x - i) == 0 && abs(y - j) % 2 == 0))
					check = true;
				else if (abs(x - i) == abs(y - j))
					check = true;
				else if (abs(x - i) % 2 == 0 && abs(y - j) % 2 == 0)
					check = true;
				else if (abs(x - i) % 2 == 1 && abs(y - j) % 2 == 1)
					check = true;
				if (check) {
					cout << "Kiriya" << endl;
					return 0;
				}
			}
		}
	}
	cout << "Lena" << endl;

	return 0;
}