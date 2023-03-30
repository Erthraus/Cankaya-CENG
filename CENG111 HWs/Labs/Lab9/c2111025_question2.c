#include <stdio.h>

int main(void){
	int n,x1,x2,ctr=0,s1,s2;
	printf("How many Integer Numbers: ");
	scanf("%d",&n);
	printf("Enter the First Number: ");
	scanf("%d",&x1);
	printf("Enter the Second Number: ");
	scanf("%d",&x2);
	
	if (x1<x2){
		s1 = x1;
		s2 = x2;
	}
		
	else{
		s1 = x2;
		s2 = x1;
	}
		
	
	for(; n-2>ctr; ctr++){
		printf("Enter the next number: ");
		scanf("%d",&x1);
		if(x1<s2 && x1>s1)
			s2 = x1;
		else if (x1<s1){
			s2 = s1;
			s1 = x1;
		}
			
	}
	
	printf("The smallest of %d numbers is %d and second smallest number is %d", n, s1, s2);
	
	return 0;
}
