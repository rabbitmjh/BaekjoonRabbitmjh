#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, c, arr[100005];
vector <p> v;

int main() {
	FIO;
	cin >> c >> n;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		v.push_back({a, b});
	}

	sort(v.begin(), v.end(), greater<>());

	int i = 0;
	while(c > arr[i]) {
		i++;
		for (int j = 0; j < n; j++) {
			if (i % v[j].first == 0)
				arr[i] = max(arr[i], (i / v[j].first) * v[j].second);
			if (i - v[j].first >= 0)
				arr[i] = max(arr[i], arr[i - v[j].first] + v[j].second);
		}
	}

	cout << i;

	return 0;
}