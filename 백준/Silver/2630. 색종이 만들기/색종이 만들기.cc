#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int p1, p2;
int map[130][130];
int n;

void go(int x, int y, int z) {
   bool chk = 1;
   int a = map[x][y];
   for (int i = x; i < x + z && chk; i++) {
      for (int j = y; j < y + z && chk; j++) {
         if (a != map[i][j]) chk = 0;
      }
   }
   if (chk) {
      if (a == 0)p1++;
      else p2++;
   }
   else {
      z /= 2;
      go(x, y, z);
      go(x, y + z, z);
      go(x + z, y, z);
      go(x + z, y + z, z);
   }
}


int main() {

   scanf("%d", &n);
   for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
         scanf("%d", &map[i][j]);
      }
   }
   go(1, 1, n);
   printf("%d\n%d", p1, p2);
}