#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int N, M, parent[100001];
ll childCnt[100001];

int Find(int A) {
    if (A != parent[A])
        parent[A] = Find(parent[A]);
    return parent[A];
}

void Union(int A, int B) {
    A = Find(A);
    B = Find(B);
    if (A == B)
        return;
    else {
        childCnt[Find(A)] += childCnt[B];
        parent[B] = Find(A);
    }
}

int main() {   
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }
    for (int i = 1, A; i <= N; i++) {
        cin >> A;
        childCnt[i] += A;
    }
    for (int i = 0, A, B; i < M; i++) {
        cin >> A >> B;
        Union(min(A, B), max(A, B));
        cout << childCnt[parent[min(A, B)]] << "\n";
    }

	return 0;
}