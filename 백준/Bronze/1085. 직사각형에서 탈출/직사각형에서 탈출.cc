#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
using namespace std;
vector <int> v;
int x, y, w, h;
int main() {
	cin >> x >> y >> w >> h;
	v.push_back(w - x);
	v.push_back(h - y);
	v.push_back(x);
	v.push_back(y);
	sort(v.begin(), v.end());
	printf("%d", v[0]);
	return 0;
}