#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int t, n, arr[10005];

int main() {
    FIO;
    cin >> t;
    while (t--) {
        cin >> n;

        arr[0] = 1;
        for (int i = 1; i < 4; i++) {
            for (int j = 1; j <= n; j++) {
                if (j - i < 0)
                    continue;
                else
                    arr[j] += arr[j - i];
            }
        }

        cout << arr[n] << "\n";
        memset(arr, 0, sizeof(arr));
    }
    return 0;
}