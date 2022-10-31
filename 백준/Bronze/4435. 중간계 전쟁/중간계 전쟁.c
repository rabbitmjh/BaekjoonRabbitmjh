#include<stdio.h>
int good[6] = { 1,2,3,3,4,10 }, evil[7] = { 1,2,2,2,3,5,10 }, t, n;
int g1[6], e1[7],sum_good,sum_evil;
int main() {
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		sum_good = 0;
		sum_evil = 0;
		for (int j = 0; j < 6; j++) {
			scanf("%d", &g1[j]);
			if (g1[j] > 0) {
				sum_good += good[j] * g1[j];
			}
		}
		for (int j = 0; j < 7; j++) {
			scanf("%d", &e1[j]);
			if (e1[j] > 0) {
				sum_evil += evil[j] * e1[j];
			}
		}
		printf("Battle %d: ", i+1);
		if (sum_good > sum_evil) {
			printf("Good triumphs over Evil\n");
		}
		else if (sum_good < sum_evil) {
			printf("Evil eradicates all trace of Good\n");
		}
		else printf("No victor on this battle field\n");
	}
	return 0;
}