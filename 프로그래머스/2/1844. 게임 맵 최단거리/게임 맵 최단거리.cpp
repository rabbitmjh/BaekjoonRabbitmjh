#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <queue>
using namespace std;
int vis[105][105];
queue <pair<pair<int, int>,int>> q;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int bfs(vector<vector<int> > maps)
{
    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second;
        q.pop();

        if (x == maps[0].size() - 1 && y == maps.size() - 1)
            return cnt;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= maps[0].size() || ny < 0 || ny >= maps.size())
                continue;
            else if (vis[ny][nx] || maps[ny][nx] == 0)
                continue;
            else
            {
                vis[ny][nx] = 1;
                q.push({ {nx,ny} ,cnt + 1 });
            }
        }
    }
    return -1;
}


int solution(vector<vector<int> > maps)
{
    vis[0][0] = 1;
    q.push({ {0,0},1 });
    return bfs(maps);
}
