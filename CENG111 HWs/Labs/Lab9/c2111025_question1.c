#include <stdio.h>

int main(void){
	char letter;
	int capital;
	
	do{
		scanf("%c", &letter);
		
		if (letter>='A' && letter<='Z')
			capital++;
		
	}while(letter != '?');
	
	printf("Number of capital letters in given text is %d", capital);
	
	return 0;
}
