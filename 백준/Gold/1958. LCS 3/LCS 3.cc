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

string s1, s2, s3;
int arr[105][105][105], ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> s1 >> s2 >> s3;
	swap(s1, s2);
	for (int i = 0; i < s1.size(); i++) {
		for (int j = 0; j < s2.size(); j++) {
			for (int k = 0; k < s3.size(); k++) {
				if (s1[i] == s2[j] && s2[j] == s3[k])
					arr[i + 1][j + 1][k + 1] = arr[i][j][k] + 1;
				else {
					int a = max(arr[i + 1][j][k], max(arr[i][j + 1][k], arr[i][j][k + 1]));
					int b = max(arr[i + 1][j + 1][k], max(arr[i + 1][j][k + 1], arr[i][j + 1][k + 1]));
					arr[i + 1][j + 1][k + 1] = max(a, b);
				}
				ans = max(ans, arr[i + 1][j + 1][k + 1]);
			}
		}
	}

	cout << ans;

	return 0;
}