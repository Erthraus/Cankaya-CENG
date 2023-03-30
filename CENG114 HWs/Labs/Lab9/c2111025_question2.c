#include <stdio.h>
#include <string.h>

int main(void)
{
	int counter = 0;
	char str1[100], str2[100], *ptr;

	gets(str1);
	gets(str2);
	
	while((ptr = strstr(str2, str1)) != NULL)
	{
		counter++;
		*ptr = ' ';
	}
	
	printf("%d", counter);
	
	return 0;
}