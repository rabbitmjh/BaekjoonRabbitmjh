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


struct Ranking
{
    int genre;
    int play;
    int index;

    bool operator<(const Ranking& other) const
    {
        if (this->genre != other.genre)
        {
            return this->genre > other.genre;
        }
        else
        {
            if (this->play != other.play)
            {
                return this->play > other.play;
            }
            else
            {
                return this->index < other.index;
            }
        }
    }
};

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> um;
    for (int i = 0; i < genres.size(); i++)
    {
        auto it = um.find(genres[i]);
        if (it != um.end())
        {
            (*it).second += plays[i];
        }
        else
        {
            um.insert({ genres[i],plays[i] });
        }
    }

    vector<Ranking> v;
    for (int i = 0; i < plays.size(); i++)
    {
        auto it = um.find(genres[i]);
        v.push_back({ (*it).second,plays[i],i });
    }

    sort(v.begin(), v.end());

    int cnt = 1;
    answer.push_back(v.front().index);
    int cmp = v.front().genre;
    for (int i = 1; i < v.size(); i++)
    {
        if (cmp == v[i].genre && cnt < 2)
        {
            answer.push_back(v[i].index);
            cnt++;
        }
        else if (cmp != v[i].genre)
        {
            cmp = v[i].genre;
            cnt = 1;
            answer.push_back(v[i].index);
        }
    }

    return answer;
}