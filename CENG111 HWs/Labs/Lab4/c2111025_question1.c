#include <stdio.h>
#include <math.h>

int main(void){
	double a,b,c,total;
	
	printf("Input 3 Numbers: ");
	scanf("%lf%lf%lf",&a,&b,&c);
	printf("Square of a= %.1f,b= %.1f,c= %.1f,total= %.2f",pow(a,2),pow(b,2),pow(c,2),pow(a,2)+pow(b,2)+pow(c,2));
	
	return(0);
}
