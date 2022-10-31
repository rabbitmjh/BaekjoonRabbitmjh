#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, num;
vector <int> v;

int main() {
	FIO;
	cin >> n; 
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());

	if (n == 2) {
		cout << 1 << endl;
		return 0;
	}
	else if (n == 3) {
		if (v.front() == 1)
			cout << 1 << endl;
		else
			cout << 2 << endl;
		return 0;
	}
	num = n;
	int sum = 0, i = 0;
	while (num > 0) {
		num -= v[i] + 1;
		sum += v[i];
		i++;
	}
	if (num < 0)
		sum += num;

	cout << sum << endl;
	return 0;
}