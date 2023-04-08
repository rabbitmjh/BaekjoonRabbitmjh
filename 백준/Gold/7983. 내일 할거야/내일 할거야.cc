#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, day;
vector <p> v;

int main() {
	FIO;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		v.push_back({ b, a });
	}
	sort(v.begin(), v.end(), greater<>());

	day = v.front().first;
	for (int i = 0; i < v.size(); i++) {
		int deadLine = v[i].first;
		int take = v[i].second;

		if (day > deadLine)
			day = deadLine;
		day -= take;
	}
	cout << day;
	return 0;
}