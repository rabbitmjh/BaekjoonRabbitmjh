#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <cstring>
using namespace std; 
vector <int> v;
queue <pair<int,int>> q;
int check[1000005];
int arr[1000005];
void bfs(int n) {
	q.push({ n,0 });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		if (x == 1) {
			return;
		}
		q.pop();
		if (x % 3==0&&check[x/3]==0) {
			arr[x / 3] = x;
			q.push({ x / 3,y + 1 });
			check[x / 3] = 1;
		}
		if (x % 2==0&&check[x/2]==0) {
			q.push({ x / 2,y + 1 });
			arr[x / 2] = x;
			check[x / 2] = 1;
		}
		if (check[x-1]==0){
			q.push({ x - 1,y + 1 });
			arr[x - 1]= x;
			check[x - 1] = 1;
		}
		check[x] = 1;
	}
}

int n;
int main() {
	scanf("%d", &n);
	bfs(n);
	int a = 1;
	while(a != n) {
		v.push_back(arr[a]);
		a = arr[a];
	}
	 
	printf("%d\n", v.size()); 
	for (int i = v.size() - 1; i >= 0; i--) {
		printf("%d ", v[i]);
	}
	printf("1");
	return 0;
}