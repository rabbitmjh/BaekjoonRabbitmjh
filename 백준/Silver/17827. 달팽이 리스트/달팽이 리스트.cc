#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
#include <utility>
#include <deque>
#include <string>
#include <limits>
#include <stack>
#include <cmath>
#include <cstring>
#include <array>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int n, m, v;
int arr[200005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	//X번째 노드는 사실 X+1번째 노드
	cin >> n >> m >> v;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int cycle = v - 1;
	while (m--) {
		int c; cin >> c;

		if (c < n)
			cout << arr[c] << "\n";
		else {
			int ans = (c - cycle) % (n - cycle) + cycle;
			//c-cycle은 사이클의 몇번째 노드인지
			//n-cycle은 사이클을 제외한 노드 개수
			cout << arr[ans] << "\n";
		}
	}

	return 0;
}