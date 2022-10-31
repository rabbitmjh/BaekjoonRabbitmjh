#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <string.h>
#include <utility>
using namespace std;
typedef pair<int, int> p;
typedef long long ll;

vector<ll>seg;
int h = 1;

using namespace std;

const int N = 1000000;
int s[4000005];
void update(int pos, int val, int id = 1, int l = 0, int r = N){
	if (l == r) {
		s[id] += val;
		return;
	}
	int mid = (l + r) >> 1;
	if (pos <= mid) {
		update(pos, val, id << 1, l, mid);
	}
	else {
		update(pos, val, id << 1 | 1, mid + 1, r);
	}
	s[id] = s[id << 1] + s[id << 1 | 1];
}

int kth(int k, int id = 1, int l = 0, int r = N){
	if (l == r) {
		return l;
	}
	int mid = (l + r) >> 1;
	if (k <= s[id << 1]) {
		return kth(k, id << 1, l, mid);
	}
	else {
		return kth(k - s[id << 1], id << 1 | 1, mid + 1, r);
	}
}
int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int a, b, c;
		scanf("%d %d", &a, &b);
		if (a == 1) {
			if (b > s[1])continue;
			int k = kth(b);
			printf("%d\n",k);
				update(k, -1);
		}
		else {
			scanf("%d\n", &c);
			update(b, c);
		}
	}
	return 0;
}
