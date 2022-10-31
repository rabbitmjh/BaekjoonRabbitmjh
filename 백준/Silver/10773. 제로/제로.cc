#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
int n,n1,sum;

int main() {
	vector <int> v;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &n1);
		if (n1 == 0)v.pop_back();
		else v.push_back(n1);
	}
	for (int i = 0; i < v.size(); i++) {
		sum += v[i];
	}
	printf("%d", sum);
	return 0;
}