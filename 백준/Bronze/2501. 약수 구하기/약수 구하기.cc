#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <stack>
using namespace std;
int n,a;
vector <int> v;
int main() {
	cin >> n >> a;
	for (int i = 1; i <= n; i++) {
		if (n%i == 0)v.push_back(i);
	}
	sort(v.begin(), v.end());
	printf("%d", v[a-1]);
	return 0;
}