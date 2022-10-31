#include<cstdio>
#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;
int n,sum,num;
string test;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		sum = 0;
		num = 0;
		cin >> test;
		for (int j = 0; j < test.size(); j++) {
			if (test[j] == 'O') {
				num++;
				sum += num;
			}
			else
				num = 0;
		}
		printf("%d\n", sum);
	}
	return 0;
}