#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>
#include <limits.h>
#include <stack>
using namespace std;
int vis[105][105];
queue <pair<pair<int, int>,int>> q;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    unordered_map<string, int> um;
    for (int i = 0; i < clothes.size(); i++)
    {
        auto it = um.find(clothes[i][1]);
        if (it != um.end())
        {
            (*it).second++;
        }
        else
        {
            um.insert({ clothes[i][1], 1 });
        }
    }

    int tmp = 1;
    for (auto it = um.begin(); it != um.end(); it++)
    {
        tmp *= ((*it).second + 1);
    }
    answer = tmp - 1;

    return answer;
}