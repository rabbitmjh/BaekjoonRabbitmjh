#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
int n,x,a;
int main() {
	vector <int> v;
	scanf("%d %d",&n,&x);
	for (int i=0; i<n; i++) {
		scanf("%d", &a);
		v.push_back(a);
	}
	for (int i = 0; i < n; i++) {
		if (v[i] < x) {
			printf("%d ", v[i]);
		}
	}
	return 0;
}