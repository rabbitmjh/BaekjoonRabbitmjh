#include<cstdio>
#include<iostream>
using namespace std;
int mon, day, sum;
int main() {
	scanf("%d %d", &mon, &day);
	sum = day % 7;
	if (mon == 1 || mon == 10) {
		if (sum == 1)
			printf("MON");
		else if (sum == 2)	
			printf("TUE");
		else if (sum == 3)
			printf("WED");
		else if (sum == 4)
			printf("THU");
		else if (sum == 5)
			printf("FRI");
		else if (sum == 6)
			printf("SAT");
		else if (sum == 0)
			printf("SUN");
		}
	else if (mon == 2 || mon == 3 || mon == 11) {
		if (sum == 5)
			printf("MON");
		else if (sum == 6)
			printf("TUE");
		else if (sum == 0)
			printf("WED");
		else if (sum == 1)
			printf("THU");
		else if (sum == 2)
			printf("FRI");
		else if (sum == 3)
			printf("SAT");
		else if (sum == 4)
			printf("SUN");
	}
	else if (mon == 4 || mon == 7) {
		if (sum == 2)
			printf("MON");
		else if (sum == 3)
			printf("TUE");
		else if (sum == 4)
			printf("WED");
		else if (sum == 5)
			printf("THU");
		else if (sum == 6)
			printf("FRI");
		else if (sum == 0)
			printf("SAT");
		else if (sum == 1)
			printf("SUN");
	}
	else if (mon == 5) {
		if (sum == 0)
			printf("MON");
		else if (sum == 1)
			printf("TUE");
		else if (sum == 2)
			printf("WED");
		else if (sum == 3)
			printf("THU");
		else if (sum == 4)
			printf("FRI");
		else if (sum == 5)
			printf("SAT");
		else if (sum == 6)
			printf("SUN");
	}
	else if (mon == 6) {
		if (sum == 4)
			printf("MON");
		else if (sum == 5)
			printf("TUE");
		else if (sum == 6)
			printf("WED");
		else if (sum == 0)
			printf("THU");
		else if (sum == 1)
			printf("FRI");
		else if (sum == 2)
			printf("SAT");
		else if (sum == 3)
			printf("SUN");
	}
	else if (mon == 8) {
		if (sum == 6)
			printf("MON");
		else if (sum == 0)
			printf("TUE");
		else if (sum == 1)
			printf("WED");
		else if (sum == 2)
			printf("THU");
		else if (sum == 3)
			printf("FRI");
		else if (sum == 4)
			printf("SAT");
		else if (sum == 5)
			printf("SUN");
	}
	else if (mon == 9 || mon == 12) {
		if (sum == 3)
			printf("MON");
		else if (sum == 4)
			printf("TUE");
		else if (sum == 5)
			printf("WED");
		else if (sum == 6)
			printf("THU");
		else if (sum == 0)
			printf("FRI");
		else if (sum == 1)
			printf("SAT");
		else if (sum == 2)
			printf("SUN");
	}
	return 0;
}