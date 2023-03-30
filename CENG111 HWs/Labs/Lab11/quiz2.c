#include <stdio.h>

int main(void){
	int lowcount=0, upcount=0, dicount=0;
	char ch;
	
	do{
		scanf(" %c", &ch);
		if(ch >= '0' && ch <= '9')
			dicount++;
		else if (ch >= 'a' && ch <= 'z')
			lowcount++;
		else if (ch >= 'A' && ch <= 'Z')
			upcount++;
		
	}while(ch != '?');
	
	printf("lowercase: %d\nuppercase: %d\ndigits: %d", lowcount, upcount, dicount);
	
	return 0;
}
