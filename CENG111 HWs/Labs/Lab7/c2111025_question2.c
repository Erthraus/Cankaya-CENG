#include <stdio.h>

int main(void){
	int x,y,counter=0,max=-999999,max2=-999999;
	while (counter<10){
		printf("a) Input a number: ");
		scanf("%d",&x);
		counter++;
		if(x>max)
			max=x;
	}
	printf("Maximum number is= %d\n",max);
	
	while(y != -999){
		printf("b) Input a number (Please enter -999 to stop): ");
		scanf("%d",&y);
		if(y>max2)
			max2=y;
	}
	printf("Maximum number is= %d",max2);
	
	
	
	return 0;
}
