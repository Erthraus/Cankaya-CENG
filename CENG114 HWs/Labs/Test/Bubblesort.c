#include <stdio.h>

void bubblesort(int arr[20], int n);
void swap(int *a, int *b);

int main(void)
{
	int arr[20], n, i;
	printf("Enter n: ");
	scanf(" %d", &n);
	printf("Enter %d numbers: ", n);
	
	for(i=0; i<n; i++)
	{
		scanf(" %d", &arr[i]);	
	}
	
	bubblesort(arr, n);
	
	for(i=0; i<n; i++)
	{
		printf("%d ", arr[i]);
	}
	
	return 0;
}

void bubblesort(int arr[20], int n)
{
	int i, j;
	
	for(i=0; i<n-1; i++)
	{
		for(j=0; j<n-i-1; j++)
		{
			if(arr[j] < arr[j+1])
				swap(&arr[j], &arr[j+1]);
		}
	}
}

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}