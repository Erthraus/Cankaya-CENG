#include <stdio.h>
#include <stdlib.h>

struct TIME
{
	int min, sec;
};

int main(void)
{
	int n, i, min=0, sec=0;
	struct TIME *arr;
	
	printf("Enter N: ");
	scanf(" %d", &n);
	
	arr  = (struct TIME*) malloc(sizeof(struct TIME)*n);
	
	for(i=0; i<n; i++)
	{
		printf("Enter %d. timestamp: ", i+1);
		scanf(" %d %d", &arr[i].min, &arr[i].sec);
	}
	
	for(i=0; i<n; i++)
	{
		sec += arr[i].sec;
		min += arr[i].min;
	}
	
	min += sec/60;
	sec = sec%60;
	
	printf("Total: %d minutes %d seconds.", min, sec);
	
	free(arr);
	return 0;
}
