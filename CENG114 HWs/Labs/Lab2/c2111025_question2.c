#include <stdio.h>

int main(void)
{
	int a[50], i;
	a[0] = 0;
	
	for(i=1; i<50; i++)
	{
		a[i] = a[i-1] + i;
	}
	
	for(i=0; i<50; i++)
	{
		printf("A[%d] = %d\n", i, a[i]);
	}
	
	return 0;
}
