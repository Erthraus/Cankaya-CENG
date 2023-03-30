#include <stdio.h>

int main(void){
	int x=1,counter;
	while(x<=9){
		for(counter=0;counter<3;counter++)
			printf("%2d",x++);
			
		printf("\n");
	}
		
	
	return 0;
	
}
