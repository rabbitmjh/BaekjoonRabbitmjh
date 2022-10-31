#include <iostream>
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>
#include <queue>
#include <string>
#include <string.h>
#include <math.h>
using namespace std;
typedef pair<int, int> p;
typedef pair<int, p> pp;
typedef long long ll;

vector <string> v[105];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a; string s;
		cin >> s >> a;
		v[i].push_back(s);
		for (int j = 0; j < a; j++) {
			string w;
			cin >> w;
			v[i].push_back(w);
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int cnt = 0;
			for (int k = 0; k < v[i].size(); k++)
				for (int l = 0; l < v[j].size(); l++)
					if (v[i][k] == v[j][l])cnt++;

			ans = max(cnt, ans);
		}
	}
	printf("%d\n", ans + 1);
	return 0;
}