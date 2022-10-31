#include<cstdio>
#include<iostream>


int n,score[1005];
float sum, count, num;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		sum = 0;
		count = 0;
		scanf("%f", &num);
		for (int j = 0; j < num; j++) {
			scanf("%d", &score[j]);
			sum += score[j];
		}
		sum = sum / num;
		for (int j = 0; j < num; j++) {
			if (score[j] > sum)count++;
		}
		printf("%.3f%%\n", 100/num*count);
		for (int j = 0; j < 1000; j++) score[j] = 0;
	}


	return 0;
}