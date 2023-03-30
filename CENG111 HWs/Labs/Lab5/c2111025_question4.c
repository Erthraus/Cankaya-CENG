#include <stdio.h>

int main(void){
	int cost,sell;
	
	printf("Input Cost Price: ");
	scanf("%d",&cost);
	printf("Input Selling Price: ");
	scanf("%d",&sell);
	
	if(sell>cost)
		printf("You may book your profit amount: %d",sell-cost);
	else if(cost>sell)
		printf("You got a loss of amount: %d",cost-sell);
	else
		printf("You are running in no profit no loss condition");
	
	return(0);
}
