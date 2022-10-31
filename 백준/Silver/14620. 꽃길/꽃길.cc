#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, arr[15][15], vis[15][15], ans = INT_MAX, cnt;
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,1,-1 };

void del(int x, int y) {
   vis[x][y] = 0;
   for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      vis[nx][ny] = 0;
   }
}

int summ(int x, int y) {
   for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (vis[nx][ny])
         return -1;
   }
   int sum = arr[x][y];
   for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      vis[nx][ny] = 1;
      sum += arr[nx][ny];
   }
   return sum;
}

void dfs(int x, int y, int cnt, int num) {
   if (cnt == 3) {
      ans = min(ans, num);
      return;
   }

   for (int i = x; i < n - 1; i++)
      for (int j = 1; j < n - 1; j++) {
         if (!vis[i][j]) {
            int sum = summ(i, j);
            if (sum != -1) {
               dfs(i, j, cnt + 1, num + sum);
               del(i, j);
            }
         }
      }
   return;
}


int main() {
   FIO;
   cin >> n;
   for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
         cin >> arr[i][j];
   
   for (int i = 1; i < n- 1; i++)
      for (int j = 1; j < n - 1; j++) {
         int sum = summ(i, j);
         dfs(i, j, 1, sum);
         del(i, j);
      }

   cout << ans;
   return 0;
}