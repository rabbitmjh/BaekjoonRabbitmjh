#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, m, check[205][205];
vector <string> v;
vector <p> ice;

int main() {
	FIO;
	cin >> n >> m;

	for (int i = 0;i < m;i++) {
		int a, b;cin >> a >> b;
		if (a > b)swap(a, b);
		check[a][b] = 1;
	}

	for (int i = 1;i <= n;i++) {
		for (int j = i + 1;j <= n;j++) {
			for (int k = j + 1;k <= n;k++) {
				if (check[i][j] || check[i][k] || check[j][k])
					continue;
				string tmp;
				tmp.append(to_string(i));
				tmp.append(to_string(j));
				tmp.append(to_string(k));
				v.push_back(tmp);
			}
		}
	}

	cout << v.size();

	return 0;
}