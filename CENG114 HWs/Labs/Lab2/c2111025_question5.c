#include <stdio.h>

int main(void)
{
	int n, i, j, ctr;
	
	while(1)
	{
		printf("Enter N (N<30): ");
		scanf(" %d", &n);
		if(n>=30)
			printf("Your numbher is too high! Try again.\n");
		else
			break;
	}
	
	int arr[n];
	
	printf("Enter %d integers: ", n);
	
	for(i=0; i<n; i++)
	{
		scanf(" %d", &arr[i]);
	}
	
	for(i=0; i<200; i++)
	{
		ctr = 0;
		for(j=0; j<n; j++)
		{
			if(arr[j] == i)
				ctr++;
		}
		
		if(ctr > 0)
			printf("%d occurs %d times\n", i, ctr);
	}
	
	
	return 0;
}