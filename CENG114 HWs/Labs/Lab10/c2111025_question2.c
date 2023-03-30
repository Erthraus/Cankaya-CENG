#include <stdio.h>
#include <string.h>

int main(void)
{
	FILE *fp = fopen("alice_in_wonderland.txt", "r");
	int max, len, i=1;
	char word[100], word2[100];
	
	while(fscanf(fp, "%s", &word) != EOF)
	{
		max = strlen(word);
		strcpy(word2, word);
		
		while(fscanf(fp, "%s", &word) != '\n')
		{
			len = strlen(word);
			if(len > max)
			{
				max = len;
				strcpy(word2, word);
			}
		}
		
		printf("Line %d: %s (%d)", i++, word2, max);
	}
	
	fclose(fp);
	return 0;
}