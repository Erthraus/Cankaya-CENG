#include <stdio.h>

int main(void){
	int n,x=1,sum=0;
	printf("Input the number of terms: ");
	scanf("%d",&n);
	for(; n>0; n--){
		sum= sum + x;
		printf("%d ",x);
		while (n-1>0){
			printf("+ ");
			break;
		}
		x=x*10+1;
	}
	printf("\nthe Sum is: %d",sum);
	
	return 0;
}
