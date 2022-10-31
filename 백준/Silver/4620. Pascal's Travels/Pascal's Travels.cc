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
char arr[105][105];

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
	while (1) {
		cin >> n;
		if (n == -1)break;
		for (int i = 0; i < n; i++)
				cin >> arr[i];

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				check[i][j] = "0";
		check[0][0] = "1";

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (check[i][j] == "0" || arr[i][j] == '0') continue;

				int down = i + arr[i][j] - '0';
				int right = j + arr[i][j] - '0';

				if (down < n) {
					check[down][j] = bigPlus(check[down][j], check[i][j]);
				}
				if (right < n) {
					check[i][right] = bigPlus(check[i][right], check[i][j]);
				}
			}
		}
		cout << check[n - 1][n - 1] << "\n";
		
	}
	return 0;
}
