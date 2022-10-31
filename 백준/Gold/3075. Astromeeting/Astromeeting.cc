#include <iostream>
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>
#include <queue>
#include <string>
#include <string.h>
#include <math.h>
#define LLONG_MAX 1e10
using namespace std;
typedef long long ll;
vector <ll>v;
ll arr[105][105];
ll t, n, p, q;

int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> p >> q;
		for (int j = 0; j < n; j++) {
			ll a;
			scanf("%lld", &a);
			v.push_back(a);
		}
		for (int j = 1; j <= p; j++) {
			for (int k = 1; k <= p; k++) {
				if (j == k)continue;
				arr[j][k] = LLONG_MAX;
			}
		}
		for (int j = 0; j < q; j++) {
			ll a, b, c;
			scanf("%lld %lld %lld", &a, &b, &c);
			arr[a][b] = min(c, arr[a][b]);
			arr[b][a] = min(c, arr[b][a]);
		}

		for (int j = 1; j <= p; j++)
			for (int k = 1; k <= p; k++)
				for (int m = 1; m <= p; m++)
					if (arr[k][m] > arr[k][j] + arr[j][m])
						arr[k][m] = arr[k][j] + arr[j][m];

		ll sum = 0, a = 0, b = LLONG_MAX;
		for (int k = 1; k <= p; k++) {
			//은하의 갯수만큼 돌림
			bool check = true;
			sum = 0;
			for (int j = 0; j < v.size(); j++) {
				//은하의 위치에서 사람이 있는 곳까지 역으로 추적
				if (arr[k][v[j]] >= LLONG_MAX) {
					check = false;
					break;
				}
				sum += pow(arr[k][v[j]], 2);
			}
			if (b > sum&&check&&sum >= 0) {
				//최저값이 0일때도 들어감
				b = sum;
				a = k;
			}
		}
		printf("%lld %lld\n", a, b);
		v.clear();
		memset(arr, 0, sizeof(arr));
	}
}