#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
int n;
int arr[1000005];
int cache[1000005];
pair<int, int> answer[1000005];
stack<int> s;

int LIS(){
	int idx = 0;
	cache[idx] = arr[0];
	answer[0] = { 0, arr[0] };

	for (int i = 1; i < n; i++)	{
		if (cache[idx] < arr[i])	{
			cache[++idx] = arr[i];
			answer[i] = { idx, arr[i] };
		}
		else{
			int idx2 = lower_bound(cache, cache + idx, arr[i]) - cache;
			cache[idx2] = arr[i];
			answer[i] = { idx2, arr[i] };
		}
	}
	return idx + 1;
}

int main(){
	cin >> n;

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	int result = LIS();
	printf("%d\n", result);
	int num = result - 1;

	for (int i = n - 1; i >= 0; i--)
		if (answer[i].first == num)	{
			s.push(answer[i].second);
			num--;
		}

	while (!s.empty())	{
		printf("%d ", s.top());
		s.pop();
	}
	return 0;
}