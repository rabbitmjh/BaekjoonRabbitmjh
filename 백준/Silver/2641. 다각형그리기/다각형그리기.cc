#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, t;
vector <int> arr, cmp, cmpR;
vector <vector<int>> ans;

bool cmpV(vector <int> a, vector <int> b, vector <int> c) {
	int tmp = n;
	while (tmp--) {
		if (a == b || a == c)
			return true;
		else {
			b.push_back(b.front());
			b.erase(b.begin());
			c.push_back(c.front());
			c.erase(c.begin());
		}
	}
	return false;
}

int main() {
	FIO;
	cin >> n;
	for (int i = 0;i < n;i++) {
		int a;cin >> a;
		arr.push_back(a);
	}

	cin >> t;
	while (t--) {
		for (int i = 0;i < n;i++) {
			int a;cin >> a;
			cmp.push_back(a);
			if (a == 1)cmpR.push_back(3);
			else if (a == 2)cmpR.push_back(4);
			else if (a == 3)cmpR.push_back(1);
			else cmpR.push_back(2);
		}

		reverse(cmpR.begin(), cmpR.end());
		if (cmpV(arr, cmp, cmpR))
			ans.push_back(cmp);

		cmp.clear();
		cmpR.clear();
	}

	cout << ans.size() << "\n";
	for (int i = 0;i < ans.size();i++) {
		for (int j = 0;j < ans[i].size();j++)
			cout << ans[i][j] << " ";
		cout << "\n";
	}

	return 0;
}