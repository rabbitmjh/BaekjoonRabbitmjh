#include<cstdio>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
string alp;
int s;
int main() {
	vector <int> a;
	for (int i = 0; i < 3; i++) {
		scanf("%d", &s);
		a.push_back(s);
	}
	sort(a.begin(), a.end());
	cin >> alp;
	if (alp == "ABC") {
		printf("%d %d %d", a[0], a[1], a[2]);
	}
	else if (alp == "ACB") {
		printf("%d %d %d", a[0], a[2], a[1]);
	}
	else if (alp == "BAC") {
		printf("%d %d %d", a[1], a[0], a[2]);
	}
	else if (alp == "BCA") {
		printf("%d %d %d", a[1], a[2], a[0]);
	}
	else if (alp == "CAB") {
		printf("%d %d %d", a[2], a[0], a[1]);
	}
	else printf("%d %d %d", a[2], a[1], a[0]);
	return 0;
}