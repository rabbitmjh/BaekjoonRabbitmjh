#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    int time = 1;
    int cnt = 0;
    int front = 0;

    vector<int> truckTime;
    truckTime.resize(truck_weights.size());

    for (int i = 0; i < truck_weights.size(); i++)
    {
        if (cnt + truck_weights[i] <= weight)
        {
            cnt += truck_weights[i];
            truckTime[i] = time;
            time++;
            if (truckTime[front] + bridge_length <= time)
            {
                cnt -= truck_weights[front];
                front++;
            }
        }
        else
        {
            while (cnt + truck_weights[i] > weight && front < i)
            {
                cnt -= truck_weights[front];
                time = truckTime[front] + bridge_length;
                truckTime[front] = time;
                front++;
            }
            cnt += truck_weights[i];
            truckTime[i] = time;
            time++;
        }
    }
    truckTime.back() += bridge_length;

    answer = truckTime.back();
    return answer;
}