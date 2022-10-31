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

int n, m, ans;
stack <int> n1, n2, n3, n4, n5, n6;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0, a, b; i < n; i++) {
		cin >> a >> b;

		if (a == 1) {
			if (n1.empty()) {
				n1.push(b);
				ans++;
			}
			else if (n1.top() < b) {
				n1.push(b);
				ans++;
			}
			else if (n1.top() > b) {
				while (n1.top() > b) {
					n1.pop();
					ans++;
					if (n1.empty())break;
				}
				if (n1.empty()) {
					n1.push(b);
					ans++;
				}
				else if (n1.top() != b) {
					n1.push(b);
					ans++;
				}
			}
		}
		else if (a == 2) {
			if (n2.empty()) {
				n2.push(b);
				ans++;
			}
			else if (n2.top() < b) {
				n2.push(b);
				ans++;
			}
			else if (n2.top() > b) {
				while (n2.top() > b) {
					n2.pop();
					ans++;
					if (n2.empty())break;
				}
				if (n2.empty()) {
					n2.push(b);
					ans++;
				}
				else if (n2.top() != b) {
					n2.push(b);
					ans++;
				}
			}
		}
		else if (a == 3) {
			if (n3.empty()) {
				n3.push(b);
				ans++;
			}
			else if (n3.top() < b) {
				n3.push(b);
				ans++;
			}
			else if (n3.top() > b) {
				while (n3.top() > b) {
					n3.pop();
					ans++;
					if (n3.empty())break;
				}
				if (n3.empty()) {
					n3.push(b);
					ans++;
				}
				else if (n3.top() != b) {
					n3.push(b);
					ans++;
				}
			}
		}
		else if (a == 4) {
			if (n4.empty()) {
				n4.push(b);
				ans++;
			}
			else if (n4.top() < b) {
				n4.push(b);
				ans++;
			}
			else if (n4.top() > b) {
				while (n4.top() > b) {
					n4.pop();
					ans++;
					if (n4.empty())break;
				}
				if (n4.empty()) {
					n4.push(b);
					ans++;
				}
				else if (n4.top() != b) {
					n4.push(b);
					ans++;
				}
			}
		}
		else if (a == 5) {
			if (n5.empty()) {
				n5.push(b);
				ans++;
			}
			else if (n5.top() < b) {
				n5.push(b);
				ans++;
			}
			else if (n5.top() > b) {
				while (n5.top() > b) {
					n5.pop();
					ans++;
					if (n5.empty())break;
				}
				if (n5.empty()) {
					n5.push(b);
					ans++;
				}
				else if (n5.top() != b) {
					n5.push(b);
					ans++;
				}
			}
		}
		else {
			if (n6.empty()) {
				n6.push(b);
				ans++;
			}
			else if (n6.top() < b) {
				n6.push(b);
				ans++;
			}
			else if (n6.top() > b) {
				while (n6.top() > b) {
					n6.pop();
					ans++;
					if (n6.empty())break;
				}
				if (n6.empty()) {
					n6.push(b);
					ans++;
				}
				else if (n6.top() != b) {
					n6.push(b);
					ans++;
				}
			}
		}
	}

	cout << ans;
	return 0;
}