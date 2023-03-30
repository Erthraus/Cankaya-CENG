#include <stdio.h>
#include <string.h>

char *secword(char arr[100])
{
	char  *token;
	token = strtok(arr, " ");
	token = strtok(NULL, " ");
	return(token);
}

int main(void)
{
	char str[100];
	int counter = 0;
	
	printf("Enter a sentence: ");
	gets(str);
	printf("Second word: %s", secword(str));
	
	return 0;
}