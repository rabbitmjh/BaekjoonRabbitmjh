#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
#include <utility>
#include <deque>
#include <string>
#include <limits.h>
using namespace std;
typedef long long ll;
vector <ll> v;
int n, m;
int dfs(int sta,int fin) {
	int count = 0;
	for (int j = 0; j < 2; j++) {
		for (int i = sta; i <= fin; i++) {
			if (v[i] > 100000000)return 0;
			if (j == 0) {
				string s = "4", a=to_string(v[i]);
				s.append(a);
				v.push_back(stoi(s));
				count++;
			}
			else {
				string s = "7", a = to_string(v[i]);
				s.append(a);
				v.push_back(stoi(s));
				count++;
			}
		}
	}
	if (v[fin] < m)dfs(fin + 1, fin+count);
	else return 0;
}


int main() {
	cin >> n >> m;
	v.push_back(4);
	v.push_back(7);
	dfs(0, 1);
	int sum = 0;
	for (int i = 0; i < v.size(); i++) 
		if (n <= v[i] && v[i] <= m)sum++;
	printf("%d", sum);
	return 0;
}