#include <stdio.h>

int main(void)
{
	int a, b, c, d, e, *p;

	printf("Enter five integers: ");
	scanf(" %d %d %d %d %d", &a, &b, &c, &d, &e);

	printf("The variables and their addresses are: ");
	printf("\nFirst: %d (addr: %p)", a, &a);
	printf("\nSecond: %d (addr: %p)", b, &b);
	printf("\nThird: %d (addr: %p)", c, &c);
	printf("\nFourth: %d (addr: %p)", d, &d);
	printf("\nFifth: %d (addr: %p)", e, &e);
	
	while(1)
	{
		printf("\nEnter variable address: ");
		scanf(" %p", &p);
		
		if(p != &a && p != &b && p != &c && p != &d && p != &e)	
			printf("You have entered a wrong address! Please try again.");
		
		else
		{
			printf("Value at given address: %d", *p);
			break;
		}
	}
	
	return 0;
}