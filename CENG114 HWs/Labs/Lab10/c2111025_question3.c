#include <stdio.h>

struct PRODUCT
{
	char name[20], type[20];
	float price;
};

int main(void)
{
	FILE *fp = fopen("menu.txt", "r");
	struct PRODUCT pdcts[10];
	float mindrink, mindessert;
	int i, locde, locdr;
	
	for(i=0; i<10; i++)
	{
		fscanf(fp, "%s %s %f\n", &pdcts[i].name, &pdcts[i].type, &pdcts[i].price);
	}
	
	for(i=0; i<10; i++)
	{
		if(pdcts[i].type == "dessert")
		{
			mindessert = pdcts[i].price;
			locde = i;
		}
	}
	
	for(i=0; i<10; i++)
	{
		if(pdcts[i].type == "drink")
		{
			mindrink = pdcts[i].price;
			locdr = i;
		}
	}
	
	for(i=0; i<10; i++)
	{
		if(pdcts[i].type == "drink" && pdcts[i].price < mindrink)
		{
			mindrink = pdcts[i].price;
			locdr = i;
		}
		
		if(pdcts[i].type == "dessert" && pdcts[i].price < mindessert)
		{
			mindessert = pdcts[i].price;
			locde = i;
		}
	}
	
	printf("Cheapest Desert = %s (%f)", pdcts[locde].name, pdcts[locde].price);
	printf("Cheapest Desert = %s (%f)", pdcts[locdr].name, pdcts[locdr].price);
		
	fclose(fp);
	return 0;
}