#include <stdio.h>

void remover(int *a, int b);

int main(void)
{
	int a, b, temp, i;
	for(i=0; i<5; i++)
	{
		printf("Input an integer and number of digits to remove from it: ");
		scanf(" %d %d", &a, &b);
		temp = a;
		remover(&a, b);
		printf("%d is modified as %d\n", temp, a);
	}

	return 0;
}

void remover(int *a, int b)
{
	for(; b>0; b--)
	{
		*a /= 10;
	}
}
