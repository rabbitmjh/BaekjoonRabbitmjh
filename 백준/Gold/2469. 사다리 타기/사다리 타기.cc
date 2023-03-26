#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int k, n, q;
char arr[1005][30];
string st, en, ans;

int main() {
	FIO;
	cin >> k >> n >>en;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i][0] == '?')
			q = i;
	}
	for (int i = 0; i < k; i++)
		st.push_back(char(i + 'A'));

	for (int i = 0; i < q; i++)
		for (int j = 0; j < k; j++)
			if (arr[i][j] == '-')
				swap(st[j], st[j + 1]);

	for (int i = n - 1; i > q; i--)
		for (int j = 0; j < k; j++)
			if (arr[i][j] == '-')
				swap(en[j], en[j + 1]);

	for (int i = 0; i < k - 1; i++) {
		if (st[i] == en[i])
			ans.push_back('*');
		else if (st[i] == en[i + 1] && st[i + 1] == en[i]) {
			ans.push_back('-');
			swap(st[i], st[i + 1]);
		}
		else {
			for (int i = 0; i < k - 1; i++)
				cout << "x";
			return 0;
		}
	}
	
	cout << ans;

	return 0;
}