#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, sum;
vector<int> v;
vector<vector<int>> edge;
vector<int> dp;

int DFS(int idx)
{
   if (dp[idx] != 0) return dp[idx];

   for (int i = 0; i < edge[idx].size(); i++) 
      dp[idx] = max(dp[idx], DFS(edge[idx][i]));

   dp[idx]++;

   return dp[idx];
}

int main()
{
   scanf("%d %d", &n, &m);
   v.resize(n + 1);
   edge.resize(n + 1);
   dp.resize(n + 1);

   for (int i = 1; i <= n; i++) scanf("%d", &v[i]);

   for (int i = 1; i <= m; i++) {
      int tmp1, tmp2;
      scanf("%d %d", &tmp1, &tmp2);

      if (v[tmp1] < v[tmp2]) edge[tmp1].push_back(tmp2);
      else edge[tmp2].push_back(tmp1);
   }

   for (int i = 1; i <= n; i++) printf("%d\n", DFS(i));

   return 0;
}