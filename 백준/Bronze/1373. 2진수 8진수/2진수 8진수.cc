#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
using namespace std;
vector <int> v;
int check[1005];
int  n1, sum;
string n;
int main() {
	cin >> n;
	for (int i = n.size()-1; i >-1; i -= 3) {		
		sum = 0;
		if (i == 1) {
			if (n[i] == '1')sum++;
			if (n[i - 1] == '1')sum += 2;
			v.push_back(sum);
			continue;
		}
		else if (i == 0) {
			if (n[i] == '1')sum++;
			v.push_back(sum);
			continue;
		}

		if (n[i] == '1')sum ++;
		if (n[i - 1] == '1')sum += 2;
		if (n[i - 2] == '1')sum+=4;
		v.push_back(sum);
	}
	for (int i = v.size()-1; i >=0; i--) {
		printf("%d", v[i]);
	}
	return 0;
}
