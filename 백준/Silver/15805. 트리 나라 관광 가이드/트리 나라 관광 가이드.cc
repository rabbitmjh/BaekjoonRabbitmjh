#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <string>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stack>
using namespace std;
typedef pair<int, int> p;
int n, m, sum;
int arr[200005];
bool vis[200005];
stack <int> st;

int main() {
	cin >> n;
	for (int i = 0; i <= n; i++)arr[i] = -1;
	for (int i = 0; i < n; i++) {
		scanf("%d", &m);
		sum = max(sum, m);
		if (!vis[m]) {
			st.push(m);
			vis[m] = true;
		}
		else {
			while (st.top() != m) {
				arr[st.top()] = m;
				st.pop();
			}
		}
	}
	printf("%d\n", sum + 1);
	for (int i = 0; i <= sum; i++)
		printf("%d ", arr[i]);

	return 0;
}