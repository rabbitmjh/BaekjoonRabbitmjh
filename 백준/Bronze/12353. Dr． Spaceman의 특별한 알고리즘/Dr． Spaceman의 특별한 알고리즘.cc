#include <iostream>
#include <algorithm>
#include <functional> 
#include <vector>
#include <utility>
#include <math.h>
#include <limits.h>
#include <cstring>
#include <string>
using namespace std;

int n;
string s;

int main() {
	cin >> n;
	for (int j = 0; j <= n; j++) {
		getline(cin, s);
		double feet = 0, inch = 0;
		for (int i = 0; i < s.size(); i++) {
			if (47 < s[i] && s[i] < 58) {
				if (i == 2 || i == 7 || i == 8) feet += (s[i]-48);
				else if (47 < s[i + 1] && s[i + 1] < 58) {
					inch += ((s[i]-48) * 10 + (s[i + 1]-48));
					i++;
				}
				else inch += s[i] - 48;
			}
		}
		if (s[0] == 'B') {
			double sum = 0;
			int	high = 0, low = 0;
			sum = feet * 12 + inch + 5;
			sum /= 2;
			high = floor(sum + 4);
			low = ceil(sum - 4);
			printf("Case #%d: %d'%d\" to %d'%d\"\n", j, low / 12, low % 12, high / 12, high % 12);
		}
		if (s[0] == 'G') {
			double sum = 0;
			int	high = 0, low = 0;
			sum = feet * 12 + inch - 5;
			sum /= 2;
			high = floor(sum + 4);
			low = ceil(sum - 4);
			printf("Case #%d: %d'%d\" to %d'%d\"\n", j, low / 12, low % 12, high / 12, high % 12);
		}
	}

	return 0;
}
