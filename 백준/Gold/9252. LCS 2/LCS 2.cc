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

string s1, s2;
int arr[1005][1005], ans;
vector <char> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> s1 >> s2;
	swap(s1, s2);
	for (int i = 0; i < s1.size(); i++) {
		int cnt = 0;
		for (int j = 0; j < s2.size(); j++) {
			if (s1[i] == s2[j])
				arr[i + 1][j + 1] = arr[i][j] + 1;
			else
				arr[i + 1][j + 1] = max(arr[i][j + 1], arr[i + 1][j]);
		}
	}

	int i = s1.size(), j = s2.size();

	while (arr[i][j]) {
		if (arr[i - 1][j] == arr[i][j])i--;
		else if (arr[i][j - 1] == arr[i][j])j--;
		else if (arr[i - 1][j - 1] == arr[i][j] - 1) {
			s.push_back(s1[i - 1]);
			i--;
			j--;
			ans++;
		}
	}
	cout << ans << "\n";
	for (int i = s.size() - 1; i > -1; i--)
		cout << s[i];

	return 0;
}