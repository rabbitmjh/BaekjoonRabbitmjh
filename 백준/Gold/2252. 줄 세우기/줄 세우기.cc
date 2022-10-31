#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 32000 + 1;

int n, m;
int inDegree[MAX];
vector<int> v[MAX];

void bfs(void){
	queue<int> q;
	for (int i = 1; i <= n; i++)
		if (!inDegree[i])
			q.push(i);
	while (!q.empty()){
		int cur = q.front();
		q.pop();
		cout << cur << " ";
		for (int i = 0; i < v[cur].size(); i++){

			inDegree[v[cur][i]]--;
			if (!inDegree[v[cur][i]])
				q.push(v[cur][i]);
		}
	}
}

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		inDegree[b]++;

	}

	bfs();
	return 0;

}