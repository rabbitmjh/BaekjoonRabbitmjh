#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <functional>
#include <queue>
#include <string>
#include <string.h>
#include <limits.h>
#include <math.h>
using namespace std;
int n, m;
vector <int> v;
int visit[9];

void go(int x, int c) {
	//c는 수열 길이 체크 x는 순서 넣기
	if (c == m) {
		for (int i = 0; i < v.size(); i++)printf("%d ", v[i]+1);
		printf("\n");
		return;
	}
	for (int i = 0; i < n; i++) {
		v.push_back(i);
		go(i , c + 1);
		v.pop_back();
	}
}

int main() {
	cin >> n >> m;
	go(0, 0);
	
	return 0;
}