#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <utility>
#include <cmath>
#include <string>
#include <string.h>
using namespace std;
typedef long long ll;
typedef pair <int, int> p;
typedef pair <int, p> pp;
vector <vector<int>> v(105);
int sum[105];
bool findroot[105];
queue<int>q;

int main() {
	int n, root = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n - 1; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		findroot[a] = true;
		sum[a]++;
	}
	for (int i = 1; i <= n; i++)
		if (!findroot[i]) {
			q.push(i);
		}
	if (q.size() > 1)printf("-1\n");
	else printf("%d\n", q.front());
	return 0;
}