#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <functional>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;
int n,sum;
int main() {
scanf("%d", &n);
for (int i = 1; i <= n; i++) {
if (n%i == 0)sum += i;
}
printf("%d", sum * 5 - 24);


return 0;
}
