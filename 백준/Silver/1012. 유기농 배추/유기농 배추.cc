#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int n, m, k, n1, n2, sum, t;
int check[55][55];
int cab[55][55];
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };

void dfs(int y, int x) {
   check[y][x] = 1;
   for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (0 <= nx < m && 0 <= ny < n && cab[ny][nx] == 1 && check[ny][nx] == 0) {
         check[ny][nx] = 1;
         dfs(ny, nx);
      }
   }
}
int main() {
   cin >> t;
   for (int l = 0; l < t; l++) {
      cin >> m >> n >> k;
      sum = 0;
      for (int i = 0; i < k; i++) {
         scanf("%d %d", &n1, &n2);
         cab[n2][n1] = 1;
      }
      for (int i = 0; i < n; i++) {
         for (int j = 0; j < m; j++) {
            if (check[i][j] == 0 && cab[i][j] == 1) {
               dfs(i, j);
               sum++;
            }
         }
      }
      printf("%d\n", sum);
      for (int i = 0; i < 55; i++) {
         memset(cab[i], 0, sizeof(cab[i]));
         memset(check[i], 0, sizeof(check[i]));
      }
   }
   return 0;
}