#include <stdio.h>

int main(void){
	int age;
	
	printf("Input the age of the candidate: ");
	scanf("%d",&age);
	
	if(age>=18)
		printf("Congratulations! The candidate is eligible for casting his/her own vote.");
	else
		printf("Sorry! The candidate is not eligible for casting his/her vote.");
		
	return(0);
}
