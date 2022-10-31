#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> p;
int n, sum, arr[9];
vector <p> v;

int main() {
	for (int i = 1; i <= 8; i++) {
		cin >> n;
		v.push_back({ n,i });
	}
	sort(v.begin(), v.end(), greater<p>());
	for (int i = 0; i < 5; i++) {
		sum += v[i].first;
		arr[v[i].second] = 1;
	}
	cout << sum << endl;
	for (int i = 1; i <= 8; i++)
		if (arr[i])printf("%d ", i);
	return 0;
}