#include <iostream>
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>
#include <queue>
#include <string>
#include <string.h>
#include <math.h>
#include <limits.h>
using namespace std;
typedef pair<int, int> p;
typedef pair<int, p> pp;
typedef long long ll;


int main() {
	int arr[4], cnt[4];
	int n;
	cin >> n;

	for (int i = 1; i <= 3; i++)
		arr[i] = i;
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < n; i++) {
		int a, b, g;
		scanf("%d %d %d", &a, &b, &g);
		int ch1 = arr[a];
		arr[a] = arr[b];
		arr[b] = ch1;
		cnt[arr[g]]++;
	}

	printf("%d", max(cnt[1], max(cnt[2], cnt[3])));

	return 0;
}