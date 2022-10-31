#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <cstring>
#include <utility>
using namespace std;
typedef pair<int, int> P;
const int INF = 1e10;
const int MAX_V = 20000;

int n, m, t;

int main() {
	int V, E, k;
	vector <P> adj[MAX_V];
	scanf("%d %d", &V, &E);
	scanf("%d", &k);
	k--;
	for (int i = 0; i < E; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		adj[u - 1].push_back(P( v - 1,w ));
	}
	int dist[MAX_V];//경로값 저장하는 배열
	fill(dist, dist + MAX_V, INF);//배열에다 INF로 다 채움
	bool visited[MAX_V] = { 0 };
	priority_queue<P, vector<P>, greater<P>>pq;// 최소값 우선순위큐
	dist[k] = 0;//시작지점 0으로
	pq.push(P(0, k));//우선순위 큐에 시작지점 넣음
	while (!pq.empty()) {//우선순위 큐가 빌때까지 돌림
		int curr;
		do {
			curr = pq.top().second;//다음지점 curr에 저장
			pq.pop();
		} while (!pq.empty() && visited[curr]);
		//curr이 방문한 정점이면 무시, 더이상 방문할 곳이 없으면 종료
		if (visited[curr])break;
		visited[curr] = true;
		for (int i = 0; i < adj[curr].size(); i++) {
			int next = adj[curr][i].first, d = adj[curr][i].second;
			//next는 다음 지점, d는 경로값
			if (dist[next] > dist[curr] + d) {
				//시작지점부터 next까지의 비용이 
				//시작지점부터 curr까지의 비용+curr->next 보다 크면 교체
				dist[next] = dist[curr] + d;
				pq.push(P(dist[next], next));
			}
		}
	}
	for (int i = 0; i < V; i++) {
		if (dist[i] == INF)printf("INF\n");
		else printf("%d\n", dist[i]);
	}
	return 0;
}
