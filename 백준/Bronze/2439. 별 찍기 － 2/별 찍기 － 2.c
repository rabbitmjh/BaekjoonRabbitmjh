int main(void) {
	int i, j, k, l;
	scanf("%d", &i);
	
	for (j = 0; j < i; j++){
		
		for (k = 1 ; k < i-j; k++) {
			printf(" ");
		}
		for (l = 0; l < j + 1; l++) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}