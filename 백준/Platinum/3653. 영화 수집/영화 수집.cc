#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;
#define MAX_N 100000
using namespace std;

int seg[8 * MAX_N], a[2 * MAX_N + 1], t, n, m, v;
int update(int pos, int val, int node, int x, int y) {
    if (y < pos || pos < x)
        return seg[node];
    if (x == y)
        return seg[node] = val;
    int mid = (x + y) >> 1;
    return seg[node] = update(pos, val, node * 2, x, mid) + update(pos, val, node * 2 + 1, mid + 1, y);
}
int query(int lo, int hi, int node, int x, int y) {
    if (y < lo || hi < x)
        return 0;
    if (lo <= x&&y <= hi)
        return seg[node];
    int mid = (x + y) >> 1;
    return query(lo, hi, node * 2, x, mid) + query(lo, hi, node * 2 + 1, mid + 1, y);
}
int main() {
    FIO;
    cin >> t;
    while (t--) {
        memset(a, 0, sizeof(a));
        memset(seg, 0, sizeof(seg));
        cin >> n >> m;
        int idx = m + 1;
        for (int i = idx; i <= n + m; i++) {
            update(i, 1, 1, 1, n + m);
            a[i - m] = i;
        }
        idx = m;
        for (int i = 0; i < m; i++) {
            cin >> v;
            cout << query(1, a[v] - 1, 1, 1, n + m) << " ";
            update(a[v], 0, 1, 1, n + m);
            a[v] = idx--;
            update(a[v], 1, 1, 1, n + m);
        }
        cout << "\n";
    }
    return 0;
}