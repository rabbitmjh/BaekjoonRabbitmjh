#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <string.h>
#include <utility>
using namespace std;

queue<pair<int, int>>q;

int t, n, m;
int arr[9], arr1[9];
bool win=false;

int main() {
	for (int i = 0; i < 9; i++) 
		scanf("%d", &arr[i]);
	for (int i = 0; i < 9; i++)
		scanf("%d", &arr1[i]);

	for (int i = 0; i < 9; i++) {
		n += arr[i];
		if (n > m&&win == false) {
			win = true;
			t++;
		}
		m += arr1[i];
		if (n < m&&win == true)win = false;
	}
	if (t>0&&!win)printf("Yes\n");
	else if(t==0&&!win)printf("No\n");
	else printf("No\n");
	return 0;
}