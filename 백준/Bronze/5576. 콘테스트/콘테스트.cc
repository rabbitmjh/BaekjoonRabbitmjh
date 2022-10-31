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

int n = 20, i = 0;
vector <int> w, k;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	while (n--) {
		int c;
		cin >> c;
		if (i < 10)
			w.push_back(c);
		else
			k.push_back(c);
		i++;
	}
	sort(w.begin(), w.end(),greater<>());
	sort(k.begin(), k.end(),greater<>());
	cout << w[0] + w[1] + w[2] << " " << k[0] + k[1] + k[2] << endl;

	return 0;
}