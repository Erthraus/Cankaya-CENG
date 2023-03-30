#include <stdio.h>

int main(void){
	int n, counter, line, blank;
	printf("Enter number of Lines: ");
	scanf("%d", &n);
	for(line=0; line<n; line++){
		for(blank = line; blank>0; blank--)
			printf(" ");
		for(counter=0; counter<3; counter++)
			printf("*");
		printf("\n");
	}
	
	return 0;
}
