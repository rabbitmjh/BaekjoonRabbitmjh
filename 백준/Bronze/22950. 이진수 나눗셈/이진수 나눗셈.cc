#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<string, int> p;
typedef pair<int, p> pp;

int n, k;
string m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k;
	int cnt = 1111111111;
	for (int i = m.size() - 1; i > -1; i--) {
		if (m[i] == '1') {
			cnt = m.size() - i - 1;
			break;
		}
	}
	if (cnt == 1111111111 || cnt >= k)cout << "YES";
	else cout << "NO";

	return 0;
}