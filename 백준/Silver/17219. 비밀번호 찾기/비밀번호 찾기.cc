#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, m;
map <string, int> site;
string sitePw[100005];

int main() {
    FIO;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string id, pw;
        cin >> id >> pw;

        site.insert({ id,i });
        sitePw[i] = pw;
    }
    
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        cout << sitePw[site[s]] << "\n";
    }

    return 0;
}