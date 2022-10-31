#include <iostream>
#include <algorithm>
#include <string.h>
#include <functional>
#include <utility>
#include <vector>
using namespace std;

vector <vector<int>> v(105);
int arr[105];

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		bool check = false;
		int a, ma = 0, b = 0;
		scanf("%d", &a);
		for (int j = 0; j < k; j++) {
			if (!v[j].empty()) {
				if (v[j].back() < a) {
					v[j].push_back(a);
					check = true;
					break;
					b = j;
				}
			}
			else {
				v[j].push_back(a);
				b = j;
				check = true;
				break;
			}
		}
		if (check == false) {
			if (ma == 0) {
				printf("NO\n");
				return 0;
			}
			else v[b].push_back(a);
		}

	}
	printf("YES\n");
	return 0;
}