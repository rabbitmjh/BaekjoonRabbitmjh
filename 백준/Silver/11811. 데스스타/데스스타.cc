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

int n, m;

string s;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int num = 0;
		for (int j = 1; j <= n; j++) {
			cin >> m;
			num = num | m;
		}
		cout << num << " ";
	}
	return 0;
}