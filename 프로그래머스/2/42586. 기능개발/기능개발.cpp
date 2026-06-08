#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> v;
    for (int i = 0; i < progresses.size(); i++)
    {
        v.push_back(((100 - progresses[i]) + (speeds[i] - 1)) / speeds[i]);
    }

    int tmp = v.front();
    int cnt = 1;
    for (int i = 1; i < v.size(); i++)
    {
        if (tmp >= v[i])
        {
            cnt++;
        }
        else
        {
            tmp = v[i];
            answer.push_back(cnt);
            cnt = 1;
        }
    }
    answer.push_back(cnt);

    return answer;
}
