#include <iostream>
#include <queue>
#include <math.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <string.h>
using namespace std;

/*
int t, n, m, a, b, q, p;
double S, A;
int arr[1005][2];

int main() {
	scanf("%d",&t);
	while (t--) {
		scanf("%d %d",&n,&m);
		int check = 0;
		vector <double> v1;

		while(m--){
			scanf("%d %d %d %d",&a,&b,&p,&q);
			if (p != 0) {
				arr[a][0] += p;
				arr[b][1] += p;
			}
			if (q != 0) {
				arr[a][1] += q;
				arr[b][0] += q;
			}
		}

		for (int i = 1; i <= n; i++) {
			S = arr[i][0];
			A = arr[i][1];
			if (S == 0 && A == 0) {
				check = 1;
			}
			else if (S == 0) {
				check = 1;
			}
			else if (A == 0) {
				v1.push_back(1000);
			}
			else {
				v1.push_back((S * S) * 1000 / (S * S + A * A));
			}
		}
		sort(v1.begin(), v1.end());
		int z = v1.back();
		int x = v1.front();
		printf("%d\n", z );
		if(check==0)printf("%d\n", x );
		else printf("0\n");
		memset(arr, 0, sizeof(arr));

	}
}



*/
int cnt;
int arr[30];

void con(int i,int n) {
	int a = n / i;
	int b = n%i;
	arr[cnt++] = b;
	if (a == 0) {
		return;
	}
	else {
		con(i, a);
	}
	return;
}



int main() {
	int n,res;
	scanf("%d", &n);
	while (n--) {
		int num;
		scanf("%d", &num);
		for (int i = 2; i <= 64; i++) {
			memset(arr, 0, sizeof(arr));
			cnt = 0;
			con(i, num);
			int s = 0;
			int e = cnt - 1;
			res=0;
			if (cnt % 2 == 0) {
				for (int j = 1; j <= cnt / 2; ++j) {
					if (arr[s++] == arr[e--]) {
						res = 1;
					}
					else {
						res = 0;
						break;
					}
				}
			}
			else {
				for (int j = 1; j <= cnt / 2 + 1; ++j) {
					if (arr[s++] == arr[e--]) {
						res = 1;
					}
					else {
						res = 0;
						break;
					}
				}
			}
			if (res) {
				break;
			}
			res = 0;
		}
		printf("%d\n",res);
		



	}
}
