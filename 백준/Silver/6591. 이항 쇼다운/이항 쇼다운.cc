#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int main(void) {
   int n, r;
   while (1) {
      scanf("%d %d", &n, &r);
      long long result = 1;
      if (n == 0 && r == 0)
         break;
      r = min(r, n - r);
      for (int i = 1; i <= r; i++) {
         result *= n;
         n--;
         result /= i;
      }
      printf("%lld\n", result);
   }
   return 0;
}
