#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;
queue<pair<int, int>>q;
int w, h,x,y,n,m;
long long arr1[100005][3];
long long arr[100005][2];

int main() {
	cin >> n;
	while (n--) {
		cin >> m;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < m; j++) {
				cin >> arr[j][i];
			}
		}
		for (int i = 1; i <= m; i++) {
			arr1[i][0] = max(max(arr1[i - 1][0], arr1[i - 1][1]), arr1[i - 1][2]);
			arr1[i][1] = max(arr1[i - 1][0], arr1[i - 1][2]) + arr[i - 1][0];
			arr1[i][2] = max(arr1[i - 1][0], arr1[i - 1][1]) + arr[i - 1][1];
		}
		printf("%lld\n", max(max(arr1[m][0], arr1[m][1]), arr1[m][2]));
		for (int i = 0; i < m; i++) {
			memset(arr1[i], 0, sizeof(arr1[i]));
			memset(arr[i], 0, sizeof(arr[i]));
		}
	}
	return 0;
}
