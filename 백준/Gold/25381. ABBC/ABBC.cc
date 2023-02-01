#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

string s;
int ans, a, b, c;
queue <int> q;

int main() {
	FIO;
	cin >> s;
	
	for (int i = 0;i < s.size();i++) {
		if (s[i] == 'B') {
			q.push(i);
		}
		else if (s[i] == 'C') {
			if (!q.empty()) {
				ans++;
				s[q.front()] = 'D';
				q.pop();
			}
		}
	}

	while (!q.empty())
		q.pop();

	for (int i = 0;i < s.size();i++) {
		if (s[i] == 'A') {
			q.push(i);
		}
		else if (s[i] == 'B') {
			if (!q.empty()) {
				ans++;
				s[q.front()] = 'D';
				q.pop();
			}
		}
	}
	cout << ans;

	return 0;
}