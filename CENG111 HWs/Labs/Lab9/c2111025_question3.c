#include <stdio.h>

int main(void){
	int n, x, line=0, ctr;
	
	printf("Input number of lines: ");
	scanf("%d", &n);
	
	for(; n>line; line++){
		ctr = n-line;
		for(; ctr>0; ctr--)
			printf(" ");
		
		for(x=1; line>=x; x++)
			printf("%d", x);
		
		for(; x>0; x--)
			printf("%d", x);
		
		printf("\n");
		
	}
	
	return 0;
}
