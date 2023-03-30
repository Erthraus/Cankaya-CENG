#include <stdio.h>

int main(void){
	int x,y,f,flag=1;
	while(flag){
		f=1;
		printf("Input x and y: ");
		scanf("%d%d",&x,&y);
		if(x*y<0){
			printf("Goodbye!");
			break;
		}
			
		else if(x*y%2==0){
			while(y>0){
				f=f*y;
				y--;
			}
				
		}
		else{
			for(;x>0;x--)
				f=f*3;
		}
			
		printf("F = %d\n",f);
	}
	
	
	return 0;
}
