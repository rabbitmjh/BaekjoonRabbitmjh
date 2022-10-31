#include <iostream>
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>
#include <queue>
#include <string>
#include <string.h>
#include <math.h>
using namespace std;
typedef pair<int, int> p;
typedef pair<int, p> pp;
typedef long long ll;

int arr[100005], ans[100005];
void go(int i) {
	for (i++; i < 100005; i += (i&-i))
		ans[i]++;
}
int getans(int i) {
	int a = 0;
	for (i++; i > 0; i -= (i&-i))
		a += ans[i];
	return a;
}

int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
		arr[i]--;
	}

	int j = n - 1;
	while (j > 0 && arr[j - 1] < arr[j])
		j--;

	printf("%d\n", j);

	for (int i = j; i < n; i++)
		go(arr[i]);
	for (int i = 0; i < j; i++){
		printf("%d ", j - 1 - i + getans(arr[i]));
		go(arr[i]);
	}

	return 0;
}