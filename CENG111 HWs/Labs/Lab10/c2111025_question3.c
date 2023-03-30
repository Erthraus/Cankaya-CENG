#include <stdio.h>
int sum_square(int n){
	int ctr, sum=0;
	for(ctr = 1; n>=ctr; ctr++){
		sum += ctr*ctr;
	}
	
	return(sum);
}

int square_sum(int n){
	int ctr, sum=0;
	for(ctr = 1; n>=ctr; ctr++){
		sum += ctr;
	}
	sum *= sum;
	return(sum);
}

int main(void){
	int n;
	printf("Enter a number: ");
	scanf("%d", &n);
	printf("Square of Sum: %d\nSum of Square: %d\nResult= %d", square_sum(n), sum_square(n), square_sum(n) - sum_square(n));
	
	return 0;
}
