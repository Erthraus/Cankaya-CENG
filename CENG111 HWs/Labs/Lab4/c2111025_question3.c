#include <stdio.h>

int main(void){
	int a,b,c;
	
	printf("Enter a three-digit binary number= ");
	scanf("%d%d%d",&a,&b,&c);
	printf("Decimal equilavent= %d",a*4+b*2+c);
	
	return(0);
}
