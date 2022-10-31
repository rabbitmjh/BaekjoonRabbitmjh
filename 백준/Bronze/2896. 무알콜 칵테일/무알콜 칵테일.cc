#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
typedef long  long ll;
typedef pair<int, int> p;

int main() {
	double a, b, c;
	cin >> a >> b >> c;
	double d, e, f;
	cin >> d >> e >> f;
	double g, h, i;
	g = a / d;
	h = b / e;
	i = c / f;

	double cnt = min(g, min(h, i));
	
	printf("%.6f %.6f %.6f\n", a - cnt*d, b - cnt*e, c - cnt*f);


	return 0;
}