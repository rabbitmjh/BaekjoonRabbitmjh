#include <iostream>
#include <algorithm>
#include <functional> 
#include <vector>
#include <utility>
#include <math.h>
using namespace std;
typedef long long ll;
typedef pair <int, int> p;

int n;
vector <p> v;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v.push_back({ a,b });
	}

	int sum=0;
	int m = 1e9;

	for (int i = v.size()-1; i >=0 ; i--) {
		if (v[i].second <= m)sum++;
		m = min(m, v[i].second);
	}

	printf("%d", sum);

	return 0;
}
