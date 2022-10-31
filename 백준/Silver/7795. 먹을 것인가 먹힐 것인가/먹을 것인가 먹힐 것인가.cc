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

int t, n, m, l, r, mid, cnt, ans;
vector <int> v, v2;

int main() {
   cin.tie(NULL);
   ios::sync_with_stdio(false);

   int t; cin >> t;
   while (t--) {
      cin >> n >> m;
      for (int i = 0; i < n; i++) {
         int a; cin >> a;
         v.push_back(a);
      }
      for (int i = 0; i < m; i++) {
         int a; cin >> a;
         v2.push_back(a);
      }
      sort(v.begin(), v.end(), greater<>());
      sort(v2.begin(), v2.end());

      cnt = v2.size();
      for (int i = 0; i < v.size(); i++) {
         l = 0, r = cnt;
         while (l + 1 < r) {
            mid = (l + r) / 2;
            
            if (v[i] > v2[mid])
               l = mid;
            else
               r = mid;
         }
         ans += l;
         if (v[i] > v2[l])
            ans++;
         cnt = r;
      }
      cout << ans << "\n";
      ans = 0;
      v.clear();
      v2.clear();
   }
   return 0;
}