#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
#include <utility>
#include <deque>
#include <string>
#include <limits>
#include <cmath>
#include <cstring>
#include <array>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int arr[105], n, m;
vector <p> v;

void female(int a, int b) {
	if (a<1 || b>n)
		return;

	if (arr[a] == arr[b]) {
		if (arr[a] == 1)
			arr[a] = arr[b] = 0;
		else
			arr[a] = arr[b] = 1;
	}
	else
		return;

	a--; b++;
	if (a<1 || b>n)
		return;
	else
		female(a, b);
}
void male(int a, int b) {
	while (a <= n) {
		if (arr[a] == 1)
			arr[a] = 0;
		else 
			arr[a] = 1;

		a += b;
	}
	return;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> arr[i];
	cin >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}

	for (int i = 0; i < v.size(); i++) {
		if (v[i].first == 1)
			male(v[i].second, v[i].second);
		else {
			if (arr[v[i].second] == 1)arr[v[i].second] = 0;
			else arr[v[i].second] = 1;
			female(v[i].second - 1, v[i].second + 1);
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << arr[i] << " ";
		if (i % 20 == 0)cout << "\n";
	}
	return 0;
}