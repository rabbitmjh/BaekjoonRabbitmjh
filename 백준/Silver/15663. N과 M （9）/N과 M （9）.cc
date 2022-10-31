#include<cstdio>
#include <algorithm>
#include<vector>
using namespace std;
int ans[10000], check[10000], visit[100005], i, n, num, m, f;
vector<int> v1;
vector<int> v2;
void go(int lo, int m) {
	if (lo == m) {
		for (i = 0; i < m; i++) {
			printf("%d ", ans[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 0; i < v1.size(); i++) {
		if (!check[i]) {
			if (i != 0 && v1[i - 1] == v1[i]) {
				if (check[i - 1]) {
					check[i] = 1;
					ans[lo] = v1[i];
					go(lo + 1, m);
					check[i] = 0;
					ans[lo] = 0;
				}
			}
			if (i == 0 || v1[i - 1] != v1[i]) {
				check[i] = 1;
				ans[lo] = v1[i];
				go(lo + 1, m);
				check[i] = 0;
				ans[lo] = 0;
			}
		}
	}
	return;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		v1.push_back(num);
	}
	sort(v1.begin(), v1.end());
	go(0, m);
	return 0;
}