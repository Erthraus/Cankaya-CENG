#include <stdio.h>

int main(void){
	int x, y, rev=0, mult=1, flag=1;
	
	printf("Enter a number: ");
	scanf("%d", &x);
	y = x;
	
	while(x>0){
		rev = rev*mult + x%10;
		while(flag==1){
			mult *= 10;
			flag = 0;
		}
			
		x = x/10;
		
	}
	
	if(rev == y)
		printf("%d is a palindrome number.", y);
		
	else
		printf("%d is not a palindrome number.", y);
		
	return 0;
	
}
