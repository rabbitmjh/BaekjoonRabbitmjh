#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <deque>
using namespace std;

deque<int> dq[5];
bool visited[5];
vector<pair<int, int>> v;
int k;

void RotateDq(int num, int direction){
	if (direction == 1){
		int tmp = dq[num].back();
		dq[num].pop_back();
		dq[num].push_front(tmp);
	}

	else if (direction == -1){
		int tmp = dq[num].front();
		dq[num].pop_front();
		dq[num].push_back(tmp);
	}
}

void Solution(int num, int direction){
	visited[num] = true;
	int prev_num = num - 1, next_num = num + 1;

	if (prev_num > 0 && !visited[prev_num]){
		if (dq[prev_num][2] != dq[num][6])
			Solution(prev_num, direction * -1);
	}
	if (next_num < 5 && !visited[next_num]){
		if (dq[next_num][6] != dq[num][2])
			Solution(next_num, direction * -1);
	}
	RotateDq(num, direction);
}

int main(){	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	for (int i = 0; i < 4; i++){
		string s;
		cin >> s;
		for (int j = 0; j < 8; j++){
			int tmp = s[j] - '0';
			dq[i + 1].push_back(tmp);
		}
	}
	cin >> k;
	for (int i = 0; i < k; i++){
		int a, b;
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
	for (int i = 0; i < v.size(); i++){
		Solution(v[i].first, v[i].second);
		memset(visited, false, sizeof(visited));
	}
	int ans = 0;
	for (int i = 1; i < 5; i++) {
		if (dq[i][0] == 1)
			ans += pow(2, i - 1);
	}
	cout << ans << "\n";
	return 0;
}