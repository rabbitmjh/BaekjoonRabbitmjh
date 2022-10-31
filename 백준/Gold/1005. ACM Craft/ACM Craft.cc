#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n;
int arr1[1001];
int arr2[1001];
int arr[1001][1001];

int bfs(int num){
	int &result = arr1[num];
	if (result != -1)
		return result;
	int time = 0;
	for (int i = 1; i <= n; i++)
		if (arr[i][num])
			time = max(time, bfs(i));
	return result = time + arr2[num];
}

int main(void){
	int t;
	cin >> t;
	for (int i = 0; i < t; i++){
		int k, d, x, y;
		cin >> n >> k;
		for (int j = 1; j <= n; j++)
			cin >> arr2[j];
		memset(arr1, -1, sizeof(arr1));
		memset(arr, 0, sizeof(arr));
		for (int j = 0; j < k; j++)	{
			cin >> x >> y;
			arr[x][y] = 1;
		}
		cin >> d;
		if (d < 0 || d>100000)
			exit(-1);
		cout << bfs(d) << endl;
	}
	return 0;

}

