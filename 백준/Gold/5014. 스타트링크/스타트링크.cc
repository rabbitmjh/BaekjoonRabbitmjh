#include <iostream>
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>
#include <queue>
#include <limits.h>
#include <math.h>
#include <string>
#include <string.h>	
using namespace std;
typedef pair<int, int> p;
int arr[1000005];
int f, s, g, u, d;
bool check = false;
queue <p> q;

void bfs(int s) {
	arr[s] = 1;
	q.push({ s,0 });
	while (!q.empty()) {
		int nextFloor = q.front().first;
		int time = q.front().second;
		q.pop();
		if (nextFloor == g) {
			printf("%d", time);
			check = true;
			return;
		}
		else {
			if (u > 0 && nextFloor + u <= f&&!arr[nextFloor + u]) {
				q.push({ nextFloor + u,time + 1 });
				arr[nextFloor + u] = 1;
			}
			if (d > 0 && nextFloor - d > 0 && !arr[nextFloor - d]) {
				q.push({ nextFloor - d,time + 1 });
				arr[nextFloor - d] = 1;
			}
		}
	}

}

int main() {
	cin >> f >> s >> g >> u >> d;
	bfs(s);
	if (!check)printf("use the stairs");
	return 0;
}