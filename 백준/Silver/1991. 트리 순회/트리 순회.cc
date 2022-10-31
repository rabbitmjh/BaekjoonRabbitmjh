#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
vector <vector<char>> v(100);
int n,m,s;
char n1, n2, n3;
char arr[55];
void plr(int i) {
	printf("%c", i);
	if (v[i][0] != '.' &&v[i][0] != 0) {
		plr(v[i][0]);
	}
	if (v[i][1] != '.' &&v[i][1] != 0) {
		plr(v[i][1]);
	}
}
void lpr(int i) {
	if (v[i][0] != '.' &&v[i][0] != 0) {
		lpr(v[i][0]);
	}
	printf("%c", i);
	if (v[i][1] != '.' &&v[i][1] != 0) {
		lpr(v[i][1]);
	}
}
void lrp(int i) {
	if (v[i][0] != '.' &&v[i][0] != 0) {
		lrp(v[i][0]);
	}
	if (v[i][1] != '.' &&v[i][1] != 0) {
		lrp(v[i][1]);
	}
	printf("%c", i);
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> n1 >> n2 >> n3;
		v[n1].push_back(n2);
		v[n1].push_back(n3);
	}
	
	plr(65);
	printf("\n");

	lpr(65);
	printf("\n");

	lrp(65);
	return 0;
}