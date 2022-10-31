#include<iostream>
#include<cstring>
#include<string>
using namespace std;
char k[5], s[5], way[5];
int n,x,y;
int main() {
	scanf("%s %s %d", k, s, &n);
	while (n--) {
		way[0] = 0, way[1] = 0;
		x = 0 , y = 0;
		scanf("%s", way);
		if (way[0] == 'L') {
			x--;
			if (way[1] == 'T')y++;
			else if (way[1] == 'B')y--;
		}
		else if (way[0] == 'R') {
			x++;
			if (way[1] == 'T')y++;
			else if (way[1] == 'B')y--;
		}
		else if (way[0] == 'B')y--;
		else if (way[0] == 'T')y++;
		if (k[0] + x > 'H' || k[0] + x<'A' || k[1] + y>'8' || k[1] + y < '1')continue;
		k[0] += x;
		k[1] += y;
		if (k[0] == s[0] && k[1] == s[1]) {
			if (s[0] + x > 'H' || s[0] + x<'A' || s[1] + y>'8' || s[1] + y < '1') {
				k[0] -= x;
				k[1] -= y;
				continue;
			}
			s[0] += x;
			s[1] += y;
		}
	}
	printf("%s\n%s", k, s);
	return 0;
}