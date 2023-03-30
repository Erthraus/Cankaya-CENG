#include <stdio.h>

int main(void){
	int x, sum=0, div=1;
	printf("Input the number: ");
	scanf("%d",&x);
	printf("The positive divisors: ");
	for(;div<=x/2;div++){
		if(x%div==0){
			sum=sum+div;
			printf("%d ",div);
		}
			
	}
	printf("\nThe sum of the divisors are: %d\n",sum);
	if(sum==x)
		printf("So, the number is perfect");
	else
		printf("So, the number is not perfect");
	
	return 0;
}
