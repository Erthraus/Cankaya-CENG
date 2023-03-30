#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[100], rev[100], *token; 
	int counter = 0, i, j;
	
	gets(str);
	token = strtok(str, " ");
	
	while(token != NULL)
	{
		counter++;
		token = strtok(NULL, " ");
	}
	
	for(j = 0; j < counter; j++)
	{
		token = strtok(str, " ");
		
		for(i = counter-j-1; i > 0; i--)
		{
			token = strtok(NULL, " ");
		}
		
		strcat(rev, token);
	}
	
	printf("%s", rev);
	
	return 0;
}