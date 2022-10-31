#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
#include<queue>
using namespace std;
int n,a,b;

int main() {
	queue <int> q;
	cin >> n >> a;
	for (int i = 1; i <= n; i++)q.push(i);
	printf("<");
	while (!q.empty()) {
		for (int i = 0; i < a; i++) {
			if (i == a-1) {
				printf("%d", q.front());
				q.pop();
				break;
			}
			b = q.front();
			q.pop();
			q.push(b);
		}
		if(q.size()>0)printf(", ");
	}
	printf(">");
	return 0;
}