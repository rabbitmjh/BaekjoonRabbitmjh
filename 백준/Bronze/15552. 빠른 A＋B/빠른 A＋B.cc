#include<cstdio>
#include<iostream>
#include<algorithm>
#include<ios>
using namespace std;
int n,n1,n2,sum;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> n1 >> n2;
		sum = n1 + n2;
		cout << sum <<"\n";
	}
	return 0;
}