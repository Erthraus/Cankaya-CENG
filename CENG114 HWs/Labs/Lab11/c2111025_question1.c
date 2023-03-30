#include <stdio.h>
#include <stdlib.h>

int prime(int x)
{
	int i;
	
	for(i=2; i<x/2; i++)
	{
		if(x%i == 0)
			return (0);
	}
	
	return (1);
}

int main(void)
{
	int n, st, i=0;
	printf("Enter N: ");
	scanf(" %d", &n);
	
	int *arr = (int*) malloc(sizeof(int)*n);
	printf("Enter starting number: ");
	scanf(" %d", &st);
	printf("Result: ");
	
	while(i<n)
	{
		if(prime(++st))
		{
			printf("%d ", st);
			i++;
		}
	}
	
	free(arr);
	return 0;
}
