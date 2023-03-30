#include <stdio.h>

int main(void){
	double a,b,c;
	
	printf("Input a,b and c= ");
	scanf("%lf%lf%lf",&a,&b,&c);
	printf("Result is= %f",(a+b)/2+3*c);
	
	return(0);
}
