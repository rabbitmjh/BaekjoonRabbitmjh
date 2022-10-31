#include <iostream>
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair <int, int> p;
priority_queue<int, vector<int>, greater<int>>q1;
priority_queue<int>q;
int n, a, L, P;
vector <p> v;

int main(){
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v.push_back({ a,b });
	}
	cin >> L >> P;
	sort(v.begin(), v.end());

	int i = 0, cnt = 0;
	while (P < L) {
		while (v[i].first <= P) {
			q.push(v[i].second);
			i++;
			if (i == n)break;
		}
	
		if (!q.size())break;
		P += q.top();
		q.pop();
		cnt++;
	}

	if (P < L)cout << -1 << endl;
	else cout << cnt << endl;
	return 0;
}