#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int>p;
typedef pair<int, p> pp;
int arr[1005], minusarr[1005];
vector <int> v;
vector <int> v1;

int main() {
	int n;
	for (int i = 0; i < 10; i++) {
		scanf("%d", &n);
		v.push_back(n);
	}
	for (int i = 0; i < 10; i++) {
		scanf("%d", &n);
		v1.push_back(n);
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			int sum = 0;
			sum = v1[j] - v[i];
			swap(v[i], v1[j]);
			
			vector<int> v2(v);
			vector<int> v3(v1);
			for (int k = 0; k < 10; k++) {
				for (int l = 0; l < 10; l++) {
					int sum1 = 0;
					sum1 = v3[l] - v2[k];
					if (sum + sum1 < 0)minusarr[abs(sum + sum1)] = 1;
					else arr[sum + sum1] = 1;
				}
			}
			swap(v[i], v1[j]);
		}
	}
	int cnt = 0;
	for (int i = 0; i < 1005; i++) {
		cnt += arr[i];
		cnt += minusarr[i];
	}
	printf("%d\n", cnt);  
	return 0;
}