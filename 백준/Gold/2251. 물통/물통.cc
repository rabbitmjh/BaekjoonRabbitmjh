#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int a, b, c, arr[205][205][205];
vector <int> ans;

void bfs() {
	arr[0][0][c] = 1;
	queue <pp> q;
	q.push({ 0,{0,c} });

	while (!q.empty()) {
		int A = q.front().first;
		int B = q.front().second.first;
		int C = q.front().second.second;
		q.pop();
		arr[A][B][C] = 1;
		
		if (A != a) {//a가 꽉 차있지 않은 경우
			if (B) {//B->A
				if (A + B > a) {
					if (!arr[a][B - (a - A)][C])
						q.push({ a,{B - (a - A),C} });
				}
				else {
					if (!arr[A + B][0][C])
						q.push({ A + B,{0,C} });
				}
			}
			if (C) {//C->A
				if (A + C > a) {
					if (!arr[a][B][C - (a - A)])
						q.push({ a,{B, C - (a - A)} });
				}
				else {
					if (!arr[A + C][B][0])
						q.push({ A + C,{B, 0} });
				}
			}
		}
		if (B != b) {
			if (A) {//A->B
				if (A + B > b) {
					if (!arr[A - (b - B)][b][C])
						q.push({ A - (b - B),{b,C} });
				}
				else {
					if (!arr[0][A + B][C])
						q.push({ 0,{A + B,C} });
				}
			}
			if (C) {//C->B
				if (B + C > b) {
					if (!arr[A][b][C - (b - B)])
						q.push({ A,{b, C - (b - B)} });
				}
				else {
					if (!arr[A][B + C][0])
						q.push({ A,{B + C, 0} });
				}
			}
		}
		if (C != c) {
			if (A) {//A->C
				if (A + C > c) {
					if (!arr[A - (c - C)][B][c])
						q.push({ A - (c - C),{B,c} });
				}
				else {
					if (!arr[0][B][C + A])
						q.push({ 0,{B,C + A} });
				}
			}
			if (B) {//B->C
				if (B + C > c) {
					if (!arr[A][B - (c - C)][c])
						q.push({ A,{B - (c - C), c} });
				}
				else {
					if (!arr[A][0][B + C])
						q.push({ A,{0, B + C} });
				}
			}
		}
	}
}

int main() {
	FIO;
	cin >> a >> b >> c;

	bfs();

	for (int j = 0;j <= 200;j++) {
		for (int k = 0;k <= 200;k++) {
			if (arr[0][j][k])
				ans.push_back(k);
		}
	}


	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	for (int i = 0;i < ans.size();i++)
		cout << ans[i] << " ";

	return 0;
}