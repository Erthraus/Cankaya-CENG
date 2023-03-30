#include <stdio.h>

int main(void){
	int x, counter1=0, counter2=0, counter3=0, sum=0;
	while(counter1<10){
		printf("Input a number: ");
		scanf("%d",&x);
		counter1++;
		if(x<100)
			sum=sum+x;
		else if(100<=x && x<=200)
			counter2++;
		else if(200<x && x%4==0)
			counter3++;
	}
	printf("The number of the numbers which are between 100 and 200: %d",counter2);
	printf("\nThe sum of the numbers which are smaller than 100: %d",sum);
	printf("\nThe number of the numbers which are greater than 200 and divisible by 4: %d",counter3);
	
	return 0;
}
