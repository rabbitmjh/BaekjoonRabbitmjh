#include <iostream>
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
#include <deque>
using namespace std;
typedef long long ll;
typedef pair<int, int>p;
typedef pair<string, p> pp;


int main() {
	int n, student = 1, num;
	cin >> n;

	while (n--) {
		bool check = true;
		for (int i = 1; i <= 10; i++) {
			cin >> num;
			if (num != (i - 1) % 5 + 1) check = false;
		}
		if (check == true)printf("%d\n", student);
		student++;
	}
	return 0;
}