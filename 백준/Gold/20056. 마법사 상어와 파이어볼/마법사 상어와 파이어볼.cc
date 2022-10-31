#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
#include <utility>
#include <deque>
#include <string>
#include <limits>
#include <cmath>
#include <cstring>
#include <array>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

struct fire {
	int m, s, d;
};
struct Treturn {
	int sM, sS;
};
int n, M, k, ans;
int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,1,1,1,0,-1,-1,-1 };
vector <fire> v[55][55], v2[55][55];

Treturn Tone(int x, int y){//질량과 속력 나누기
	Treturn Tr;
	int sumM = 0, sumS = 0;
	for (int i = 0; i < v2[x][y].size(); i++) {
		sumM += v2[x][y][i].m;
		sumS += v2[x][y][i].s;
	}
	Tr.sM = sumM / 5; //나누어진 파이어볼의 질량
	Tr.sS = sumS / v2[x][y].size(); //나누어진 파이어볼의 속력
	v2[x][y].clear();
	return Tr;
}

bool Tthree(int x, int y) {//파이어볼의 방향 체크
	bool odd = false;
	bool even = false;
	for (int i = 0; i < v2[x][y].size(); i++) {
		if (!(v2[x][y][i].d % 2)) even = true;
		else odd = true;
	}
	if (even && odd) return true;
	else return false;
}

void move() {//이동
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int q = 0; q < v[i][j].size(); q++) {
				int nm = v[i][j][q].m;//질량
				int ns = v[i][j][q].s;//속력
				int nd = v[i][j][q].d;//방향
				if (ns % n == 0) {
					vector <fire> tem = v2[i][j];
					v2[i][j].clear();
					tem.push_back({ nm,ns,nd });
					v2[i][j] = tem;
				}
				else {
					int nx = i + dx[nd] * (ns % n);
					int ny = j + dy[nd] * (ns % n);
					if (nx < 1)nx += n;
					if (nx > n)nx -= n;
					if (ny < 1)ny += n;
					if (ny > n)ny -= n;
					vector <fire> tem = v2[nx][ny];
					v2[nx][ny].clear();
					tem.push_back({ nm,ns,nd });
					v2[nx][ny] = tem;
				}
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	//m:질량 s:속력 d:방향
	cin >> n >> M >> k;
	int r, c, d, m, s;
	for (int i = 0; i < M; i++) {
		cin >> r >> c;
		cin >> m >> s >> d;
		v[r][c].push_back({ m, s, d });
	}
	while (k--) {
		move();//이동
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (v2[i][j].size() > 1) {//2개 이상 있을때
					vector <fire> tem;
					bool check = Tthree(i, j);//방향체크
					Treturn a = Tone(i, j);//질량 속력
					if (a.sM == 0)continue;
					
					if (check) {//1,3,5,7
						tem.push_back({ a.sM,a.sS,1 });
						tem.push_back({ a.sM,a.sS,3 });
						tem.push_back({ a.sM,a.sS,5 });
						tem.push_back({ a.sM,a.sS,7 });
					}
					else {//0,2,4,6
						tem.push_back({ a.sM,a.sS,0 });
						tem.push_back({ a.sM,a.sS,2 });
						tem.push_back({ a.sM,a.sS,4 });
						tem.push_back({ a.sM,a.sS,6 });
					}
					v2[i][j] = tem;
				}
			}
		}
		swap(v, v2);//이동한 결과 값과 이전 값을 바꿔줌
		memset(v2, 0, sizeof(v2));// 이전 값 초기화
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int q = 0; q < v[i][j].size(); q++)
				ans += v[i][j][q].m;
	
	cout << ans;

	return 0;
}