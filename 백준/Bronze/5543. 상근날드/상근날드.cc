#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n,n1,n2;
int main() {
	vector <int> v;
	scanf("%d %d %d", &n,&n1,&n2);
	v.push_back(n);
	v.push_back(n1);
	v.push_back(n2);
	sort(v.begin(), v.end());
	scanf("%d %d", &n, &n1);
	if (n > n1)	printf("%d", v[0] + n1 - 50);
	else printf("%d", v[0] + n - 50);

	return 0;
}