#include <iostream>
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair <int, int> p;
const int MAX = 100005;
vector<vector<int>> adj;
stack<int> s;

bool finish[MAX];
int dfsn[MAX], SCCnum[MAX], indegree[MAX];
int SCCtotal, cnt;

int dfs(int cur)
{
	dfsn[cur] = ++cnt;

	s.push(cur);

	int result = dfsn[cur];

	int len = adj[cur].size();

	for (int i = 0; i < len; i++)
	{
		int next = adj[cur][i];

		if (!dfsn[next])
			result = min(result, dfs(next));

		else if (!finish[next])
			result = min(result, dfsn[next]);
	}

	if (result == dfsn[cur])
	{
		while (1)
		{
			int t = s.top();
			s.pop();
			finish[t] = true;
			SCCnum[t] = SCCtotal;

			if (t == cur)
				break;
		}

		SCCtotal++;
	}

	return result;
}

int main()
{
	int tc;
	scanf("%d", &tc);
	while (tc--)
	{
		int V, E;
		scanf("%d %d", &V, &E);

		memset(finish, false, sizeof(finish));
		memset(dfsn, 0, sizeof(dfsn));
		memset(SCCnum, 0, sizeof(SCCnum));
		memset(indegree, 0, sizeof(indegree));
		adj.clear();
		adj.resize(V + 1);
		cnt = 0;
		SCCtotal = 0;

		for (int i = 0; i < E; i++)
		{
			int from, to;
			scanf("%d %d", &from, &to);
			adj[from].push_back(to);
		}

		for (int i = 0; i < V; i++)
			if (!dfsn[i])
				dfs(i);

		for (int i = 0; i < V; i++)
			for (int j : adj[i])
				if (SCCnum[i] != SCCnum[j])
					indegree[SCCnum[j]]++;

		int cntdegree = 0;
		int target = 0;
		for (int i = 0; i < SCCtotal; i++)
			if (indegree[i] == 0)
				target = i, cntdegree++;

		if (cntdegree > 1)
			printf("Confused\n");
		else
			for (int i = 0; i < V; i++)
				if (SCCnum[i] == target)
					printf("%d\n", i);

		printf("\n");
	}
	return 0;
}