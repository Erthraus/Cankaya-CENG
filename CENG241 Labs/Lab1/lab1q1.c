#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int main(void)
{
	int n1, n2, n3, i, j, *arr1, *arr2, *arr3;
	
	printf("Enter length of first array: ");
	scanf("%d", &n1);
	
	arr1 = (int*) malloc(n1 * sizeof(int));
	
	printf("Enter numbers: ");
	for(i=0; i<n1; i++)
	{
		scanf(" %d", &arr1[i]);
	}
	
	printf("Enter length of second array: ");
	scanf("%d", &n2);
	
	arr2 = (int*) malloc(n2 * sizeof(int));
	
	printf("Enter numbers: ");
	for(i=0; i<n2; i++)
	{
		scanf(" %d", &arr2[i]);
	}
	
	n3 = n1 + n2;
	arr3 = (int*) malloc(n3 * sizeof(int));
	
	for(i=0; i<n1; i++)
	{
		arr3[i] = arr1[i];
	}
	
	free(arr1);
	
	for(i=0; i<n2; i++)
	{
		arr3[n3-i-1] = arr2[i];
	}
	
	free(arr2);
	
	for(i=0; i<n3-1; i++)
	{
		for(j=0; j<n3-i-1; j++)
		{
			if(arr3[j] > arr3[j+1])
				swap(&arr3[j], &arr3[j+1]);
		}
	}
	
	printf("Merged Array: ");
	for(i=0; i<n3; i++)
	{
		printf("%d ", arr3[i]);
	}
	
	free(arr3);
	
	return (0);
}
