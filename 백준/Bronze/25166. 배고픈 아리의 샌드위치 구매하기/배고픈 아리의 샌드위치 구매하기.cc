#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, m, arr[10];

int main() {
	FIO;
	cin >> n >> m;
	if (1023 >= n)cout << "No thanks";
	else {
		int a = n - 1023, q = 0, i = 9;
		while (i > -1) {
			if (m - pow(2, i) >= 0) {
				arr[i] = 1;
				m -= pow(2, i);
			}
			i--;
		}
		i = 0;
		while (i < 10) {
			if (arr[i] && a - pow(2, i) >= 0) {
				q += pow(2, i);
				a -= pow(2, i);
			}
			i++;
		}
		

		if (!a && q + 1023 == n)cout << "Thanks";
		else cout << "Impossible";
	}

	

	return 0;
}
