#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <string>
#include <string.h>
#include <math.h>
#include <limits.h>
using namespace std;
typedef pair<int, int> p;
int student[10005];
int need[10005];

int find(int x) {
	if (student[x] < 0)return x;
	return student[x] = find(student[x]);
}
void mearge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)return;
	if (need[x] > need[y])student[x] = y;
	else student[y] = x;
	return;
}

int main() {
	int n, m, money;
	fill(student, student + 10005, -1);
	cin >> n >> m >> money;
	for (int i = 1; i <= n; i++)
		scanf("%d", &need[i]);
	fill(student, student + 10005, -1);

	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		mearge(a, b);
	}
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		if (student[i] == -1)sum += need[i];
	}

	if (money < sum)printf("Oh no");
	else printf("%d", sum);
	return 0;
}