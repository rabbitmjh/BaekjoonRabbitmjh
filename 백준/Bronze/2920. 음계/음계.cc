#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n,num,sum,num1,sum1;
int main() {
	vector <int> v;
	for (int i = 0; i < 8; i++) {
		scanf("%d", &n);
		v.push_back(n);
	}
	num1 = 9;
	for (int i = 0; i < 8; i++) {
		if (v[i] > num) {
			num = v[i];
			sum++;
		}
		if (v[i] < num1) {
			num1 = v[i];
			sum1++;
		}
	}
	if (sum == 8)printf("ascending");
	else if (sum1 == 8)printf("descending");
	else printf("mixed");
	return 0;
}