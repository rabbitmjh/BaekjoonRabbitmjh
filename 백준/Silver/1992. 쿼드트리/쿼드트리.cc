#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
#include <utility>
#include <deque>
#include <string>
#include <limits>
#include <cmath>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;
//백준 1992 쿼드트리

int n;
char arr[100][100];
vector <char> v;

void dfs(int x1, int y1, int x2, int y2){
	int white = 0, black = 0;
	for(int i = x1; i < x2; i++) {
		for(int j = y1; j < y2; j++){
			if(arr[i][j] == '0') white++;
			else black++;
		}
	}
	
	if(x1 == x2 && y1 == y2) {
		v.push_back(arr[x1][y1]);
		return;
	}
	if(!white) {
		v.push_back('1');
		return;
	}
	else if(!black) {
		v.push_back('0');
		return;
	}
	else {
		v.push_back('(');
		dfs(x1, y1, (x1 + x2) / 2, (y1 + y2) / 2);
		dfs(x1, (y1 + y2) / 2, (x1 + x2) / 2, y2);
		dfs((x1 + x2) / 2, y1, x2, (y1 + y2) / 2);
		dfs((x1 + x2) / 2, (y1 + y2) / 2, x2, y2);
		v.push_back(')');
	}
}

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	
	scanf("%d", &n);
	for(int i = 0; i < n; i++) 
		scanf("%s", arr[i]);
	
	dfs(0, 0, n, n);
	
	for(int i = 0; i < v.size(); i++)
		printf("%c", v[i]);
	
	
	return 0;
}
