#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<ll, ll> p;
typedef pair<p, int> pp;

ll n, k, sum;
int chk[5005];
vector <p> v;

int main() {
   FIO;
   cin >> n >> k;
   for (int i = 0; i < n; i++) {
      int a; cin >> a;
      v.push_back({ a,i });
   }
   
   sort(v.begin(), v.end(),greater<>());
   for (int i = 0; i < k; i++)
      chk[v[i].second] = 1;

   int cnt = 0;
   for (int i = 0; i < 5001; i++) {
      if (cnt > 0 && chk[i]) {
         chk[i] = cnt;
         cnt++;
      }
      if (cnt == 0 && chk[i]) {
         chk[i]--;
         cnt++;
      }
   }
   for (int i = 0; i < k; i++)
      sum += v[i].first - chk[v[i].second];

   cout << sum;

   return 0;
}
