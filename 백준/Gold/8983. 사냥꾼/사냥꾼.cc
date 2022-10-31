#include<iostream>
#include<vector>
#include<cmath>

using namespace std;
typedef pair<int, int> P;

int m, n, l, result;
vector<int> animal[100001], visit[100001], v;

void go(int stX) {
	for (int i = 1; i <= l; i++) {
		if (!animal[i].empty()) {
			for (int j = 0; j < animal[i].size(); j++) {
				if (visit[i][j] != 1) {
					if (abs(animal[i][j] - stX) + i <= l) {
						visit[i][j] = 1;
						result++;
					}
				}
			}
		}
	}
}

int main() {
	int i, a, b;
	scanf("%d %d %d", &m, &n, &l);
	for (i = 0; i < m; i++){
		scanf("%d", &a);
		v.push_back(a);
	}
	for (i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		animal[b].push_back(a);
		visit[b].push_back(0);
	}

	for (i = 0; i < v.size(); i++) {
		go(v[i]);
	}

	printf("%d\n", result);

	return 0;
}