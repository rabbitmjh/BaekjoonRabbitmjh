#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n;
float num,high,sum;
int main() {
	vector <float> v;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%f", &num);
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	high = v[n-1];
	for (int i = 0; i < n; i++) {
		v[i] = v[i] / high * 100;
		sum += v[i];
	}
	printf("%.2f", sum / n);
	return 0;
}