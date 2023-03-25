#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int N, parent[1000005], childCnt[1000005];
char M;

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
        childCnt[Find(A)] += childCnt[Find(B)];
        parent[B] = Find(A);
    }
}

int main() {
    FIO;

    cin >> N;
    for (int i = 1; i <= 1000000; i++) {
        parent[i] = i;
        childCnt[i] = 1;
    }

    for (int i = 0, A, B; i < N; i++) {
        cin >> M;
        if (M == 'I') {
            cin >> A >> B;
            Union(min(A, B), max(A, B));
        }
        else {
            cin >> A;
            cout << childCnt[parent[Find(A)]] << "\n";
        }
    }

    return 0;
}