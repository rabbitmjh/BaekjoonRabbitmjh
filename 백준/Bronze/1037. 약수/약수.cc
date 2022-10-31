#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
using namespace std;
vector <int> v;
int n,a;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	printf("%d", v.front()*v.back());
	return 0;
}