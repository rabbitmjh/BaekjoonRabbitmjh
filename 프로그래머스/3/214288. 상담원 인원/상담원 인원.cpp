#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int solution(int k, int n, vector<vector<int>> reqs) {
    int answer = 0;
    
    vector<pair<int, int>> v[6];
int arr[6][2], cnt[6] = { 1,1,1,1,1,1 };
memset(arr, 0, sizeof(arr));

int mx = 0;

for (int i = 0;i < reqs.size();i++) {
	int time = reqs[i][0];
	int dur = reqs[i][1];
	int type = reqs[i][2];
	v[type].push_back({time,dur});
}

for (int i = 1;i <= k;i++) {
	int cur = 0;//가장 빠른 시간
	for (int j = 0;j < v[i].size();j++) {
		if (cur > v[i][j].first) {
			arr[i][0] += cur - v[i][j].first;
			cur += v[i][j].second;
		}
		else {
			cur = v[i][j].first + v[i][j].second;
		}
	}
}

int t = n - k;
while (t--) {
	for (int go = 1;go <= k;go++) {
		priority_queue<int, vector<int>, greater<int>>pq;
		for (int i = 0;i < v[go].size();i++) {
			int tStart = v[go][i].first;
			int tEnd = v[go][i].second;

			if (pq.size() < cnt[go] + 1) {
				pq.push(tStart + tEnd);
			}
			else {
				if (pq.top() <= tStart) {
					pq.pop();
					pq.push(tStart + tEnd);
				}
				else {
					arr[go][1] += pq.top() - tStart;
					pq.push(pq.top() + tEnd);
					pq.pop();
				}
			}
		}
	}
	int choice = 0, tmp = -1;
	for (int i = 1;i <= k;i++) {
		if (arr[i][0] - arr[i][1] > choice) {
			choice = arr[i][0] - arr[i][1];
			tmp = i;
		}
	}
	if (tmp != -1){
		arr[tmp][0] = arr[tmp][1];
        cnt[tmp]++;
    }
    for (int i = 1;i <= k;i++) {
	arr[i][1] = 0;
    }
}
for (int i = 1;i <= k;i++)
	answer += arr[i][0];
    
    return answer;
}