#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int n, n1, n2;
vector<int> v;
int main() {
	cin >> n >> n1 >> n2;
	v.push_back(n);
	v.push_back(n1);
	v.push_back(n2);
	sort(v.begin(), v.end());
	for(int i=0;i<3;i++) {
		printf("%d ", v[i]);
	}
	return 0;
}
