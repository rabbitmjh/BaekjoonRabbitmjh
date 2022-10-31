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

long long n;
string check[105][105];
long long arr[105][105];

string bigPlus(string s1, string s2) {
	string cmp;
	int num = 0;
	while(s1.size() > s2.size())
		s2.insert(0, "0");
	while (s1.size() < s2.size())
		s1.insert(0, "0");
	for (int i = s1.size() - 1; i > -1; i--) {
		int a = s1[i]-'0';
		int b = s2[i]-'0';
		num = a + b + num;
		string c = to_string(num % 10);
		cmp.insert(0, c);
		num /= 10;
		if (i == 0 && num > 0)
			cmp.insert(0, to_string(num));
	}
	return cmp;
}


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			check[i][j] = "0";
	check[1][1] = "1";

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (check[i][j] == "0" || arr[i][j] == 0) continue;

			long long down = i + arr[i][j];
			long long right = j + arr[i][j];

			if (down <= n) {
				check[down][j] = bigPlus(check[down][j], check[i][j]);
			}
			if (right <= n) {
				check[i][right] = bigPlus(check[i][right], check[i][j]);
			}
		}
	}
	cout << check[n][n];

	return 0;
}
