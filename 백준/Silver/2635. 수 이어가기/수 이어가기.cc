#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n;
vector <int> v, tmp;

void go(int num, int now) {
	tmp.push_back(now);
	if (num - now < 0)return;
	else go(now, num - now);
}

int main() {
	FIO;
	cin >> n;

	for (int i = 1;i <= n;i++) {
		tmp.push_back(n);
		go(n, i);
		if (tmp.size() > v.size())
			v = tmp;
		tmp.clear();
	}

	cout << v.size() << "\n";
	for (int i = 0;i < v.size();i++)
		cout << v[i] << " ";

	return 0;
}