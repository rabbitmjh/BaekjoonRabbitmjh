#include <iostream>
#include <algorithm>
#include <cstring>
#include <functional>
#include <vector>
#include <queue>
using namespace std;
vector <int> v;
int c, n;
int arr[100005];

int main() {
	scanf("%d", &c);
	for (int i = 0; i < c; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < c; i++) {
		n = arr[i];
		int sum = 1;
		for (int j = i+1; j < c; j++) {
			if (n == arr[j] - 1) {
				n = arr[j];
				sum++;
			}
		}

		v.push_back(sum);

	}
	sort(v.begin(), v.end());
	printf("%d", v.back());
	return 0;
}

