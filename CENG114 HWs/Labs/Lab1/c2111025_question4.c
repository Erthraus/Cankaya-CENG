#include <stdio.h>

void func(int x, int y);                              //Function for a
void func2(int x, int y, int *p1, int *p2);           //Function for b

int main(void)
{
	int x, y;
	printf("a) Enter two integers: ");
	scanf(" %d %d", &x, &y);
	func(x, y);
	
	printf("\nb) Enter two integers: ");
	scanf(" %d %d", &x, &y);
	func2(x, y, &x, &y);
	printf("Result: %d %d", x, y);
	
	return 0;
}

void func(int x, int y)
{
	int tx=0, ty=0, i=0;
	
	if(y > x)
	{
		tx = x;
		x = y;
		y = tx;
	}
	
	else
	{
		tx = x % 10;
		x /= 10;
		ty = y % 10;
		y /= 10;
		while(x>0)
		{
			tx = tx*10 + (x%10);
			x /= 10;
		}
		
		while(y>0)
		{
			ty = ty*10 + (y%10);
			y /= 10;
		}
		
		x = tx; y = ty;
	}
	
	printf("Result: %d %d", x, y);
}

void func2(int x, int y, int *p1, int *p2)
{
	int tx=0, ty=0, i=0;
	
	if(y > x)
	{
		tx = x;
		x = y;
		y = tx;
		*p1 = x; *p2 = y;
	}
	
	else
	{
		tx = x % 10;
		x /= 10;
		ty = y % 10;
		y /= 10;
		while(x>0)
		{
			tx = tx*10 + (x%10);
			x /= 10;
		}
		
		while(y>0)
		{
			ty = ty*10 + (y%10);
			y /= 10;
		}
		
		*p1 = tx; *p2 = ty;
	}
	
}