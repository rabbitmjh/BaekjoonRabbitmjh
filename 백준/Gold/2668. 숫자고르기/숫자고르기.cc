#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>

using namespace std;
const int MAX = 100 + 1;
int n,cnt;
int node[MAX];
bool visited[MAX];
bool cycle[MAX];
bool dfs(int startNum, int nodeNum){
	if (visited[nodeNum])
		return false;
	visited[nodeNum] = true;
	if (startNum == nodeNum || dfs(startNum, node[nodeNum])){
		cnt++;
		cycle[nodeNum] = true;
		return true;
	}
	return false;
}
int main(void){
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> node[i];
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++)
			visited[j] = cycle[j];
		dfs(i, node[i]);
	}
	cout << cnt << endl;
	for (int i = 1; i <= n; i++)
		if (cycle[i]) 
			cout << i << endl;
	cout << endl;
	return 0;
}