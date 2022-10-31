#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int n, w, b;
int main() {
	vector <int> rope;
	rope.reserve(100001);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &b);
		rope.push_back(b);
	}
	sort(rope.begin(),rope.end());
	for (int i = 0; i < n; i++) {
		if (w < rope.at(i)*(n-i)) {
			w = rope.at(i)*(n-i);
		}
	}
	printf("%d", w);
	return 0;
}