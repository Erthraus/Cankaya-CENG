#include <stdio.h>

int main(void)
{
	int n, i;
	char ch;
	while(1)
	{
		printf("Enter a number (N<30): ");
		scanf(" %d", &n);
		if(n>=30)
			printf("Your numbher is too high! Try again.\n");
		else
			break;
	}

	char arr[n];
	
	for(i=0; i<n; i++)
	{
		printf("Enter the %d. character for array: ", i+1);
		scanf(" %c", &arr[i]);
	}
	
	printf("Enter the character you want to remove: ");
	scanf(" %c", &ch);
	
	for(i=0; i<n; i++)
	{
		if(ch == arr[i])
			arr[i] = '\b';
		printf(" %c", arr[i]);
	}

	return 0;
}
