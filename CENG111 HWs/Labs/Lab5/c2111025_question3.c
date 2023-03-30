#include <stdio.h>
#include <math.h>

int main(void){
	float A,B,C,x,n;
	
	printf("Input A, B, C, x and n: ");
	scanf("%f%f%f%f%f",&A,&B,&C,&x,&n);
	
	printf("Result= %f",A*pow(x,n)+B*pow(x,n-1)+C*pow(x,n-2));
	
	return(0);
}
