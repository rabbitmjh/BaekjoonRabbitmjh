#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int t, n, m, k;
vector<int> bob, alice, sB, sA;

void go(vector<int>& v, vector<int>& sumV) {
	vector <int> tmp;
	for (int i = 0; i < k; i++)
		tmp.push_back(1);
	for (int i = 0; i < v.size() - k; i++)
		tmp.push_back(0);
	sort(tmp.begin(), tmp.end());

	do {
		int sum = 0;
		for (int i = 0; i < tmp.size(); i++)
			if (tmp[i])
				sum += v[i];
		sumV.push_back(sum);
	} while (next_permutation(tmp.begin(), tmp.end()));
	return;
}

int main() {
	FIO;
	cin >> t;
	while (t--) {
		cin >> n >> m >> k;
		for (int i = 0; i < n; i++) {
			int a; cin >> a;
			bob.push_back(a);
		}
		for (int i = 0; i < m; i++) {
			int a; cin >> a;
			alice.push_back(a);
		}
		sort(bob.begin(), bob.end());
		sort(alice.begin(), alice.end());

		go(bob, sB);
		go(alice, sA);
		sort(sB.begin(), sB.end());
		sort(sA.begin(), sA.end());
		int ansMin = 1e10, ansMax = 0;

		ansMax = max(abs(sA.back() - sB.front()), abs(sA.front() - sB.back()));
		for (int i = 0; i < sB.size(); i++) {
			auto it = lower_bound(sA.begin(), sA.end(), sB[i]);

			int tmp = it - sA.begin();
			if (it == sA.end()) {
				tmp--;
				ansMin = min(ansMin, abs(sB[i] - sA[tmp]));
			}
			else if (tmp == 0)
				ansMin = min(ansMin, abs(sB[i] - sA[tmp]));
			else
				ansMin = min(ansMin, min(abs(sB[i] - sA[tmp]), abs(sB[i] - sA[tmp - 1])));
		}

		cout << ansMin << " " << ansMax << "\n";
		bob.clear();
		alice.clear();
		sB.clear();
		sA.clear();
	}

	return 0;
}