#include<cstdio>
#include<iostream>
using namespace std;

int n,n1,n2,n3,x,y;
int main() {
	scanf("%d %d %d %d", &n,&n1,&n2,&n3);
	int sum = n + n1 + n2 + n3;
	y = sum % 60;
	x = sum / 60;
	printf("%d\n%d", x, y);
	return 0;
}