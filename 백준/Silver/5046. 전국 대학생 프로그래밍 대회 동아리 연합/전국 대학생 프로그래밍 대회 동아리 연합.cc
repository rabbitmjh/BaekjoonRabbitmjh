#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, b, h, w, p, a;

int main() {
	vector <int> v;
	cin >> n >> b >> h >> w;
	for (int i = 0; i < h; i++) {
		cin >> p;
		for (int j = 0; j < w; j++) {
			cin >> a;
			if (n*p < b&&n < a)v.push_back(n*p);
		}
	}
	sort(v.begin(), v.end());
	if(!v.empty())printf("%d", v.front());
	else printf("stay home");
	return 0;
}