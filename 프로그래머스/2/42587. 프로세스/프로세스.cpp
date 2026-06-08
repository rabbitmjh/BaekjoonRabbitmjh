#include <string>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int cnt = 1;
    int mx = 0;
    int idx = 0;
    while (cnt <= priorities.size())
    {
        int st = idx;
        for (int i = st; i < priorities.size(); i++)
        {
            if (mx < priorities[i])
            {
                mx = priorities[i];
                idx = i;
            }
        }
        for (int i = 0; i < st; i++)
        {
            if (mx < priorities[i])
            {
                mx = priorities[i];
                idx = i;
            }
        }
        if (location == idx)
        {
            answer = cnt;
            break;
        }

        priorities[idx] = -1;
        cnt++;
        mx = 0;
    }
    return answer;
}