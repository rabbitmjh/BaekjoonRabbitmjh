#include<cstdio>
#include<iostream>

int n,m,Ai[1005][2],Bj[1005],s = -1,sum;

int main() {
	scanf("%d %d", &n,&m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &Ai[i][0]);
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d", &Bj[i]);
		for (int j = 1; j <= n; j++) {
			if(Bj[i]>=Ai[j][0]){
				Ai[j][1] += 1;
				break;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (Ai[i][1] > s) {
			s = Ai[i][1];
			sum = i;
		}
	}
	printf("%d", sum);
	return 0;
}