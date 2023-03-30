#include <stdio.h>

int main(void)
{
	int n, i, j;
	double a[10], temp, temp2;
	
	for(i=0; i<10; i++)
	{
		printf("Enter the %d. number: ", i+1);
		scanf(" %lf", &a[i]);
	}
	
	printf("Enter how many times you want to rotate: ");
	scanf(" %d", &n);
	
	for(i=0; i<n; i++)
	{
		temp = a[9];
		for(j=9; j>0; j--)
		{
			a[j] = a[j-1];
		}
		a[0] = temp;
	}
	
	for(i=0; i<10; i++)
	{
		printf("%.2f ", a[i]);
	}
	
	return 0;
}
