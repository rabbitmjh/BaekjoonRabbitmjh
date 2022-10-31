#include<cstdio>
#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
using namespace std;
int sum, n, a, b;
int main(){
	scanf("%d", &n);
	vector <int> A;
	vector <int> B;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		A.push_back(a);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &b);
		B.push_back(b);
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), greater<int>());
	for (int i = 0; i < n; i++) {
		sum += A[i] * B[i];
	}
	printf("%d", sum);
	return 0;
}