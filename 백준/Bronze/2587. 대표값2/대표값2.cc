#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int a, sum;
vector <int> v;

int main() {
	FIO;
	for (int i = 0; i < 5; i++) {
		cin >> a;
		sum += a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	cout << sum / 5 << "\n" << v[2];

	return 0;
}