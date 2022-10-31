#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <queue>
#include <string>
#include <cstring>
using namespace std;
int arr[35];
int n, c, m;
vector <string> v;

int main() {
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &m);
		v.clear();
		int d = 0;
		memset(arr,0,sizeof(arr));
		for (int j = 0; j < m; j++) {
			string s, a;
			c = 0;
			cin >> s;
			cin >> a;
			for (int i = 0; i < v.size(); i++) {
				if (a == v[i]) {
					arr[i]++;
					c = 1;
				}
			}
			if (c == 0) {
				v.push_back(a);
			}
		}
		int sum = 1;
		for (int i = 0; i < v.size(); i++) {
			sum *= (arr[i] + 2);
		}
		printf("%d\n", sum - 1);
	}

	return 0;
}