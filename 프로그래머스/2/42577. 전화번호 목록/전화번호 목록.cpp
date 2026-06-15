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

bool solution(vector<string> phone_book) {
    bool answer = true;

    unordered_map<string, int> pb;
    for (int i = 0; i < phone_book.size(); i++)
    {
        pb.insert({ phone_book[i], i });
    }
    for (int i = 0; i < phone_book.size(); i++)
    {
        string tmp = "";
        for (int j = 0; j < phone_book[i].size(); j++)
        {
            tmp += phone_book[i][j];
            auto it = pb.find(tmp);
            if (it != pb.end() && (*it).second != i)
            {
                answer = false;
            }
        }
    }

    return answer;
}