#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<ll, ll> p;
typedef pair<int, p> pp;

int n, k, a, b, arr[105], h, ans;
bool dead = false;

int water(int cur) {
	int cnt = 0;
	for (int i = cur;i < n;i++) {
		if (cnt == a) {
			return i;
		}
		arr[i] += b;
		cnt++;
	}
	if (cnt < a) {
		for (int i = 0;i < n;i++) {
			if (cnt == a) {
				return i;
			}
			arr[i] += b;
			cnt++;
		}
	}
	if (cur + a > n) {
		return cur + a - n;
	}
	else return cur + a;
}

void dry() {
	for (int i = 0;i < n;i++) {
		arr[i]--;
		if (!arr[i])dead = true;
	}
	return;
}

int main() {
	FIO;
	cin >> n >> k >> a >> b;
	for (int i = 0;i < n;i++)
		arr[i] = k;

	while (dead == false) {
		h = water(h);
		dry();
		ans++;
	}

	cout << ans;

	return 0;
}
