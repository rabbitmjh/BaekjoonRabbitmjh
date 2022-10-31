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

int n;
string s;
char arr[5][20];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
	}

	int cnt = 0;
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 5; j++) {
			if (arr[j][i] == '\0')continue;
			else cout << arr[j][i];
		}
	}

		
	return 0;
}