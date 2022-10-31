#include <iostream>
#include <algorithm>
#include <cstring>
#include <functional>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;
int n, m;
queue <pair<int, int>>q;
int arr[70][70];
int check[70][70];
void bfs() {
   q.push({ 1,1 });
   while (!q.empty()) {
      int x = q.front().first;
      int y = q.front().second;
      if (arr[x][y] == -1) {
         printf("HaruHaru");
         return;
      }
      q.pop();
      int nx = arr[x][y] + x;
      int ny = arr[x][y] + y;
      if (nx <= n && check[nx][y] == 0) {
         check[nx][y] = 1;
         q.push({ nx,y });
      }
      if (ny <= n && check[x][ny] == 0) {
         check[x][ny] = 1;
         q.push({ x,ny });
      }
   }
   printf("Hing");

}


int main() {
   scanf("%d", &n);
   for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
         scanf("%d", &arr[i][j]);
      }
   }
   bfs();


}
