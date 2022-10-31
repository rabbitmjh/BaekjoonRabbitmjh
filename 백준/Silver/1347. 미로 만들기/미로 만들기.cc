#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
#include <utility>
#include <deque>
#include <string>
#include <limits>
#include <cmath>
#include <cstring>
#include <array>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p> pp;

int num, x = 52, y = 52, minx = 52, maxx = 52, miny = 52, maxy = 52;
string str;
vector <char> v;
char d = 'S', map[105][105];

char dir(char d, char c){
	if (d == 'S') {
		if (c == 'L')d = 'E';
		else d = 'W';
	}
	else if (d == 'W') {
		if (c == 'L')d = 'S';
		else d = 'N';
	}
	else if (d == 'N') {
		if (c == 'L')d = 'W';
		else d = 'E';
	}
	else {
		if (c == 'L')d = 'N';
		else d = 'S';
	}
	return d;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> num >> str;
	memset(map, '#', sizeof(map));
	map[x][y] = '.';

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'L' || str[i] == 'R') d = dir(d, str[i]);
		else v.push_back(d);
	}
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == 'S')x++;
		else if (v[i] == 'E')y++;
		else if (v[i] == 'W')y--;
		else x--;
		map[x][y] = '.';
		minx = min(minx, x);
		miny = min(miny, y);
		maxx = max(maxx, x);
		maxy = max(maxy, y);
	}

	for (int i = minx; i <= maxx; i++) {
		for (int j = miny; j <= maxy; j++)
			cout << map[i][j];
		cout << "\n";
	}
	return 0;
}