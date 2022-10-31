#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

int n, c;
using namespace std;
int w, h;
int width;

int main(void) {
   cin >> n >> c;
   w = n, h = n;
   for (int i = 0; i < c; i++) {
      int a, b;
      cin >> a >> b;
      if (a > w || b > h)
         continue;

      if (a * h > b * w) {
         w = a;
      }
      else if (a * h < b * w) {
         h = b;
      }
      else if (a * h == b * w) {
         w = a;
      }
   }

   cout << w * h;
   return 0;
}
