#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, ans, cnt, arr[22][22];
vector <p> imp;

p check(p st, p en) {
	int a = 0, b = 0;
	for (int i = st.first; i <= en.first; i++) {
		for (int j = st.second; j <= en.second; j++) {
			if (arr[i][j] == 1)a++;
			else if (arr[i][j] == 2)b++;
		}
	}
	return { a,b };
}

int cutting(p st, p en, int m) {
	p many = check(st, en);
	if (many.second - many.first > 1 || !many.second)return 0;
	if (!many.first && many.second == 1)return 1;

	int sum = 0;
	for (int i = st.first; i <= en.first; i++) {
		for (int j = st.second; j <= en.second; j++) {
			if (arr[i][j] == 1) {
				if (m) {
					if (i + 1 >= n || i - 1 < 0)continue;
					p xx = check({ i,st.second }, { i,en.second });
					if (!xx.second)
						sum += cutting( st,{i - 1,en.second},0 ) * cutting({ i + 1,st.second }, en, 0);
				}
				else {
					if (j + 1 >= n || j - 1 < 0)continue;
					p yy = check({ en.first,j }, { st.first,j });
					if (!yy.second)
						sum += cutting(st, { en.first,j - 1 }, 1) * cutting({ st.first,j + 1 }, en, 1);
				}
			}
		}
	}
	return sum;
}

int main() {
	FIO;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1)
				imp.push_back({ i,j });
			else if (arr[i][j] == 2)
				cnt++;
		}

	if (!cnt && imp.empty()) {
		cout << 0;
		return 0;
	}
	ans = cutting({ 0,0 }, { n - 1,n - 1 }, 0) + cutting({ 0,0 }, { n - 1,n - 1 }, 1);
	if (!ans)cout << -1;
	else cout << ans;

	return 0;
}