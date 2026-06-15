#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    sort(routes.begin(), routes.end());

    int s = routes[0][0];
    int e = routes[0][1];
    for (int i = 1; i < routes.size(); i++)
    {
        int ns = routes[i][0];
        int ne = routes[i][1];

        if (e >= ns)
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