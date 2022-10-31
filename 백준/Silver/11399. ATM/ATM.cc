#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,n1,sum1,sum;
int main() {
	vector <int> v;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &n1);
		v.push_back(n1);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		sum1 = 0;
		for (int j = 0; j <= i; j++) {
			sum1 += v[j];
		}
		sum += sum1;
	}
	printf("%d", sum);
	return 0;
}