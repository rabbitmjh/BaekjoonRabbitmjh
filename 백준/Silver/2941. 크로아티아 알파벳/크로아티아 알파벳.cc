#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
string a;
int sum;
int main() {
	cin >> a;
	for (int i = 0; i < a.length(); i++) {
		if (a[i] == 'c'&&a[i + 1] == '=') {
			sum++;
			i++;
		}
		else if (a[i] == 'c'&&a[i + 1] == '-') {
			sum++;
			i++;
		}
		else if (a[i] == 'z'&&a[i + 1] == '=') {
			sum++;
			i++;
		}
		else if (a[i] == 's'&&a[i + 1] == '=') {
			sum++;
			i++;
		}
		else if (a[i] == 'd'&&a[i + 1] == '-') {
			sum++;
			i++;
		}
		else if (a[i] == 'd'&&a[i + 1] == 'z'&&a[i + 2] == '=') {
				sum++;
				i += 2;
		}
		else if (a[i] == 'l'&&a[i + 1] == 'j') {
			sum++;
			i++;
		}
		else if(a[i]=='n'&&a[i+1]=='j'){
			sum++;
			i++;
		}
		else sum++;
	}
	printf("%d", sum);
	return 0;
}