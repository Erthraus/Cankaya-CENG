#include <stdio.h>

void uplow(char x);
void uplowc(char x, int *p);

int main(void)
{
	char x;
	int i, flag = 2;
	printf("a) Enter a letter: ");
	scanf(" %c", &x);
	uplow(x);
	
	printf("\n\nb) Enter 20 letters: ");
	for(i=0; i<20; i++)
	{
		scanf(" %c", &x);
		uplow(x);
	}
	
	printf("\n\nc) Enter a letter: ");
	scanf(" %c", &x);
	uplowc(x, &flag);

	if(flag == 1)
		printf("\n%c is an uppercase letter.", x);

	else if(flag == 0)
		printf("\n%c is a lowercase letter.", x);
		
	return 0;
}

void uplow(char x)                    //Function for a and b
{
	if(x >= 'A' && x <= 'Z')
		printf("\n%c is an uppercase letter.", x);
	
	else if(x >= 'a' && x <= 'z')
		printf("\n%c is a lowercase letter.", x);
		
	else
		printf("\nYour input is not a letter!");
}

void uplowc(char x, int *p)                 //Function for c
{
	if(x >= 'A' && x <= 'Z')
		*p = 1;
	
	else if(x >= 'a' && x <= 'z')
		*p = 0;
		
	else
		printf("\nYour input is not a letter!");	
}