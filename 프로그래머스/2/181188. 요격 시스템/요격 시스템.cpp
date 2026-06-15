#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 1;
    sort(targets.begin(), targets.end());

    int s = targets[0][0];
    int e = targets[0][1];
    for (int i = 1; i < targets.size(); i++)
    {
        int ns = targets[i][0];
        int ne = targets[i][1];

        if (e > ns)
        {
            s = ns;
            e = min(e, ne);
        }
        else
        {
            answer++;
            s = ns;
            e = ne;
        }
    }

    return answer;
}