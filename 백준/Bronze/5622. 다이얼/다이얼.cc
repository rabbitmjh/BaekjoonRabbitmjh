#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<string>
#include<string.h>
using namespace std;
int sum;
int main() {
	string v;
	cin >> v;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == 'A' || v[i] == 'B' || v[i] == 'C') sum += 3;
		else if (v[i] == 'D' || v[i] == 'E' || v[i] == 'F') sum += 4;
		else if (v[i] == 'G' || v[i] == 'H' || v[i] == 'I')sum += 5;
		else if (v[i] == 'J' || v[i] == 'K' || v[i] == 'L')sum += 6;
		else if (v[i] == 'M' || v[i] == 'N' || v[i] == 'O')sum += 7;
		else if (v[i] == 'P' || v[i] == 'Q' || v[i] == 'R' || v[i] == 'S')sum += 8;
		else if (v[i] == 'T' || v[i] == 'U' || v[i] == 'V')sum += 9;
		else if (v[i] == 'W' || v[i] == 'X' || v[i] == 'Y' || v[i] == 'Z')sum += 10;
	}
	printf("%d", sum);
	return 0;
}