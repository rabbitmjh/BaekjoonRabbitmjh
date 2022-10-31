#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <stack>
using namespace std;
string a,b;
int n,n1,n2,n3;

int main() {
	while (getline(cin,a)) {
		n = 0, n1 = 0, n2 = 0, n3 = 0;
		
		for (int i = 0; i < a.size(); i++) {
			if (97 <= a[i] && a[i] <= 122)n++;
			else if (65 <= a[i] && a[i] <= 90)n1++;
			else if (48 <= a[i] && a[i] <= 57)n2++;
			else if (a[i] == ' ')n3++;
		}
		if (n == 0 && n1 == 0 && n2 == 0 && n3 == 0)break;
		printf("%d %d %d %d\n", n, n1, n2, n3);
		b = a;
	}
	return 0;
}