#include<stdio.h>
#include<iostream>
#include<queue>
#include<string>
using namespace std;
int n,num;
string a;
int main() {
	queue <int> q;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a == "push") {
			scanf("%d", &num);
			q.push(num);
		}
		else if (a == "front") {
			if (q.empty() == 1) printf("-1\n"); 
			else printf("%d\n", q.front());
		}
		else if (a == "back") {
			if (q.empty() == 1) printf("-1\n");
			else printf("%d\n", q.back());
		}
		else if (a == "size") printf("%d\n", q.size());
		else if (a == "empty") printf("%d\n", q.empty());
		else if (a == "pop") {
			if (q.empty() == 1)printf("-1\n");
			else {
				printf("%d\n", q.front());
				q.pop();
			}
		}
	}
	return 0;
}