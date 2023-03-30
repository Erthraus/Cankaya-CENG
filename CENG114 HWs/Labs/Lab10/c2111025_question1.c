#include <stdio.h>

int main(void)
{
	FILE *fp = fopen("alice_in_wonderland.txt", "r");
	int ctr = 0;
	char word[100];
	
	printf("Words starting with capital letters:\n");
	
	while(fscanf(fp, "%s", &word) != EOF)
	{
		if(word[0] >= 'A' && word[0] <= 'Z')
		{
			printf("%s\n", word);
			ctr++;				
		}
	}
	
	printf("Total: %d", ctr);
	
	fclose(fp);
	return 0;
}