#include<stdio.h>
int nation[1002][4], n, g, s, b, nt,num,rank=1;
int main() {
	scanf("%d %d", &n, &nt);
		for (int i = 1; i <= n; i++) {
			scanf("%d %d %d %d", &num, &g, &s, &b);
			nation[i][0] = num;
			nation[i][1] = g;
			nation[i][2] = s;
			nation[i][3] = b;
	}
		for (int i = 1; i <= n; i++) {
			if (nation[nt][1] <= nation[i][1]) {
				if (nation[nt][1] == nation[i][1]) {
					if (nation[nt][2] <= nation[i][2]) {
						if (nation[nt][2] == nation[i][2]) {
							if (nation[nt][3] <= nation[i][3]) {
								if (nation[nt][3] == nation[i][3]) {
									rank += 0;
									break;
								}
								rank++;
								break;
							}
						}
						else;
						rank++;
						break;
					}
				}
				else;
				rank++;
			}
			else;
			rank += 0;
		}
		printf("%d", rank);
	return 0;
}