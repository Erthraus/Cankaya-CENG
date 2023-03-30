#include <stdio.h>

void power(void);                                      //Function for a
void power2(int x, int y, int *p1, int *p2);           //Function for b

int main(void)
{
	int x, y, res1 = 1, res2 = 1;
	
	power();
	
	printf("\nb) Enter 2 numbers: ");
	scanf(" %d %d", &x, &y);
	power2(x, y, &res1, &res2);
	
	if(x==0 && y==0)
		return 0;
	
	printf("%d^%d = %d", x, y, res1);
	printf("\n%d^%d = %d", y, x, res2);
	
	return 0;
}

void power(void)
{
	int x, y, tx, ty, res1=1, res2=1;
	
	printf("a) Enter 2 numbers: ");
	scanf(" %d %d", &x, &y);
	
	if(x==0 && y==0)
		printf("ERROR");
	
	else
	{
		for(ty = y; ty>0; ty--)
		{
			res1 *= x;
		}
	
		for(tx = x; tx>0; tx--)
		{
			res2 *= y;
		}
	
		printf("%d^%d = %d", x, y, res1);
		printf("\n%d^%d = %d", y, x, res2);
	}
	
}

void power2(int x, int y, int *p1, int *p2)
{
	int tx, ty;
	
	if(x==0 && y==0)
		printf("ERROR");
	
	else
	{
		for(ty = y; ty>0; ty--)
		{
			*p1 *= x;
		}
	
		for(tx = x; tx>0; tx--)
		{
			*p2 *= y;
		}
	
	}
}