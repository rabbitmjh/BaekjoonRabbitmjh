#include <cstdio>
#include<algorithm>
using namespace std;
int arr[10], check[10], ans[10];
int n, sum = 0;
int go(int lo, int sum) {
   if (sum == 100 && lo == 7) {
      for (int j = 0; j < 9; j++) {
         if (check[j]) {
            printf("%d\n", arr[j]);
         }
      }
      return 1;
   }
   else if (lo >= 7 || sum>100)return 0;
   else {
      for (int i = 0; i < 9; i++) {
         if (!check[i]) {
            check[i] = 1;
            if (go(lo + 1, sum + arr[i])) return 1;
            check[i] = 0;
         }
      }
   }
   return 0;
}
int main(void) {
   for (int i = 0; i < 9; i++) {
      scanf("%d", &arr[i]);
   }
   sort(arr, arr + 9);
   go(0, 0);
   return 0;
}
