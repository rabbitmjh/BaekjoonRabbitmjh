#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n,num;
int main() {
	vector <int> v;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		printf("%d\n", v[i]);
	}
	return 0;
}