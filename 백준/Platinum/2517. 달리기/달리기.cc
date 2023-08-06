#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n;
vector <p> arr;
vector <int> tree;

void updateTree(int node, int left, int right, int index, int diff) {
    if (index < left || right < index) return;

    tree[node] += diff;

    if (left != right) {
        int mid = (left + right) / 2;
        updateTree(node * 2, left, mid, index, diff);
        updateTree(node * 2 + 1, mid + 1, right, index, diff);
    }
}

int queryTree(int node, int left, int right, int start, int end) {
    if (end < left || right < start) return 0;
    if (start <= left && right <= end) return tree[node];
    int mid = (left + right) / 2;
    return queryTree(node * 2, left, mid, start, end) + queryTree(node * 2 + 1, mid + 1, right, start, end);
}

int main() {
    FIO;

    cin >> n;
    arr.resize(n);

    for (int i = 0; i < n; ++i) {
        arr[i].first = i;
        cin >> arr[i].second;
    }

    sort(arr.begin(), arr.end(), [](const auto &a, const auto &b) {
        return a.second < b.second;
    });
    
    for (int i = 0; i < n; ++i)
        arr[i].second = i;

    int treeHeight = ceil(log2(n));
    int treeSize = 1 << (treeHeight + 1);
    tree.resize(treeSize, 0);

    vector <p> result(n);

    for (int i = n - 1; i >= 0; --i) {
        result[i].first = arr[i].first;
        result[i].second = queryTree(1, 0, n - 1, 0, arr[i].first - 1) + 1;
        updateTree(1, 0, n - 1, arr[i].first, 1);
    }

    sort(result.begin(), result.end());
    for (auto i : result) {
        cout << i.second << "\n";
    }

    return 0;
}